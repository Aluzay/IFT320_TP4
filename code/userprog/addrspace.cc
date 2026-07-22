// addrspace.cc 
//	Routines to manage address spaces (executing user programs).
//
//	In order to run a user program, you must:
//
//	1. link with the -N -T 0 option 
//	2. run coff2noff to convert the object file to Nachos format
//		(Nachos object code format is essentially just a simpler
//		version of the UNIX executable object code format)
//	3. load the NOFF file into the Nachos file system
//		(if you haven't implemented the file system yet, you
//		don't need to do this last step)
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "addrspace.h"


#ifdef USER_PROGRAM

extern int SysCallRead(OpenFile*, int,int,int);
extern int SysCallWrite(OpenFile*, int,int,int);
#endif

static void SwapHeader (NoffHeader *);

extern BitMap* freeFrame;

//----------------------------------------------------------------------
// AddrSpace::AddrSpace
// 	Create an address space to run a user program.
//	Load the program from a file "executable", and set everything
//	up so that we can start executing user instructions.
//
//	Assumes that the object code file is in NOFF format.
//
//	First, set up the translation from program memory to physical 
//	memory.  For now, this is really simple (1:1), since we are
//	only uniprogramming, and we have a single unsegmented page table
//
//	"executable" is the file containing the object code to load into memory
//----------------------------------------------------------------------

void AddrSpace::loadFromExecutable(int page){
  
  if(page < 0 || page>=numPages){
    DEBUG('e',"loadFromExecutable: page %d out of range\n",page);
    return;
  }
  
  if(pageTable[page].valid==TRUE){
    DEBUG('e',"loadFromExecutable: page %d already in memory\n",page);
    return;
  }
  
  int cadre = freeFrame->Find();
  ASSERT(cadre != -1);

  // Calculer l'adresse virtuelle du debut de la page
  /*
  exemple: si PageSize = 128, alors
  Page 0 → pageStart =   0
  Page 1 → pageStart = 128
  Page 2 → pageStart = 256
  Page 9 → pageStart = 1152
  */
  int pageStart = page * PageSize;

  // Calculer la taille de la zone code + initData du programme.
  int initializedSize = executableHeader.code.size
                      + executableHeader.initData.size;

  char *frame = &(machine->mainMemory[cadre * PageSize]);

  // Les zones uninitialized data et pile commencent remplies de zeros.
  // garantit que la pile commence a zeros, et que les variables non-initialisees sont initialement a zero.
  bzero(frame, PageSize);

  // Les executables du TP commencent a l'adresse virtuelle 0 et les
  // sections code et initData sont contigues.
  ASSERT(executableHeader.code.virtualAddr == 0);
  
  // Si la page demandee est dans la zone code+initData, on la charge depuis le fichier executable.
  // Exemple avec initializedSize = 256 et PageSize = 128 :
  // pages 0 et 1 -> lecture du fichier; page 9 (pile) -> reste a zero.
  if(pageStart < initializedSize) {
    // quantite totale - quantite situee avant cette page = quantite restante a lire
    int bytesToRead = initializedSize - pageStart;
    if(bytesToRead > PageSize)
      bytesToRead = PageSize;

    int fileOffset = executableHeader.code.inFileAddr + pageStart;
    int bytesRead = executableFile->ReadAt(frame,
                                           bytesToRead,
                                           fileOffset);
    ASSERT(bytesRead == bytesToRead);
  }

  // La traduction devient valide seulement lorsque le contenu est pret.
  pageTable[page].physicalPage = cadre;
  pageTable[page].valid = TRUE;
  pageTable[page].use = FALSE;
  pageTable[page].dirty = FALSE;
  
}

AddrSpace::AddrSpace(OpenFile *executable)
{
    
    unsigned int size;
    
	NoffHeader noffH;
	
		
    executable->ReadAt((char *)&noffH, sizeof(noffH), 0);
    if ((noffH.noffMagic != NOFFMAGIC) && (WordToHost(noffH.noffMagic) == NOFFMAGIC))
    	SwapHeader(&noffH);
    ASSERT(noffH.noffMagic == NOFFMAGIC);

    executableHeader = noffH;
    executableFile = executable;

	// how big is address space?
    size = noffH.code.size + noffH.initData.size + noffH.uninitData.size + UserStackSize;		
    numPages = divRoundUp(size, PageSize);
    size = numPages * PageSize;

	
	//IFT320: verifie si espace suffisant pour charger le programme.	
	
	
	DEBUG('a', "espace libre =  %d, \n", freeFrame->NumClear());
	// ASSERT(numPages <= freeFrame->NumClear());	
    


    DEBUG('a', "Initializing address space, num pages %d, size %d\n",numPages, size);

    pageTable = new TranslationEntry[numPages];
    for (int i = 0; i < numPages; i++) {
	
		pageTable[i].virtualPage = i;	// for now, virtual page # = phys page #
 
		//IFT320 trouve un cadre libre, le nettoie et l'assigne.
		
		// int cadre = freeFrame->Find(); 		
		// bzero(&(machine->mainMemory[cadre*PageSize]), PageSize); 		
		pageTable[i].physicalPage = -1;		
		
		pageTable[i].valid = FALSE;	//Traduction valide ou non
		
		pageTable[i].use = FALSE;	//Utilisee dernierement (read ou write)
		pageTable[i].dirty = FALSE;	//Modifiee dernierement (write)
		pageTable[i].readOnly = FALSE;  //Interdite en ecriture ou non
    }

	//IFT320: on assume que le AddrSpace est construit par le Thread associe.
	//C'est-a-dire, PAS par le Thread qui demande l'exec de ce programme, mais
	//par celui qui a ete cree pour rouler ce programme.
	//Sinon, BIG BADA BOOM
	RestoreState();
	
	
	
	//IFT320: chargement du programme au complet.	
	// SysCallRead(executable,noffH.code.virtualAddr,noffH.code.size,noffH.code.inFileAddr);
	
	// if(noffH.initData.size>0){
	// 	SysCallRead(executable,noffH.initData.virtualAddr,noffH.initData.size,noffH.initData.inFileAddr);		
	// }
	
}




//----------------------------------------------------------------------
// AddrSpace::~AddrSpace
// 	Dealloate an address space.  Nothing for now!
//----------------------------------------------------------------------

AddrSpace::~AddrSpace()
{
	
	
	//IFT320: liberation des cadres
	int i;
	DEBUG('e',"Liberation des cadres...\n");
	for (i = 0; i < numPages; i++){
		if(pageTable[i].valid && pageTable[i].physicalPage >= 0)
			freeFrame->Clear(pageTable[i].physicalPage); //libere cadre
	}

	delete pageTable;
}

void AddrSpace::PrintPageTable(){

	DEBUG('l',"Page table contents for thread %s:0x%x\n",currentThread->getName(),(int)currentThread);
	DEBUG('l',"\n V |   P   | v | u | d | ro\n");
	for (int i = 0; i < numPages; i++) {		
		DEBUG('l',"%2d | %5d | ",pageTable[i].virtualPage,pageTable[i].physicalPage);	
		DEBUG('l',"%d | %d | %d | %d\n",pageTable[i].valid,pageTable[i].use,pageTable[i].dirty,pageTable[i].readOnly);
    }
}

//IFT320: Affiche le contenu d'une page, octet par octet. 
//Le parametre "swapPos" sera utilise plus tard pour comparer le contenu avec ce qu'il y a dans 
//le fichier d'echanges. 
void AddrSpace::PrintPage(int page,int swapPos){

	DEBUG('a',"----Page %d contents----",page);
	unsigned char content[128];
	
	if(pageTable[page].valid==TRUE){
		DEBUG('a',"Valid, in frame %d:\n",pageTable[page].physicalPage);
		memcpy(content,&(machine->mainMemory[pageTable[page].physicalPage*PageSize]),128);
		for (int i=0;i<128;i++){
			DEBUG('a',"%2x ",content[i]);
		}
	}
	else{
		DEBUG('a',"Invalid, not in memory.\n");
	}	
	
	if(swapPos>=0){
		DEBUG('l',"\nPage in swap, occupies block %d:\n",swapPos);
		
		//IFT320: ajoutez ici l'affichage du contenu du swap correspondant a la page
	}
	else{
		DEBUG('l',"\nPage Not in swap. \n",swapPos);	
	}	
	
}

//----------------------------------------------------------------------
// AddrSpace::InitRegisters
// 	Set the initial values for the user-level register set.
//
// 	We write these directly into the "machine" registers, so
//	that we can immediately jump to user code.  Note that these
//	will be saved/restored into the currentThread->userRegisters
//	when this thread is context switched out.
//----------------------------------------------------------------------

void
AddrSpace::InitRegisters()
{
    int i;

    for (i = 0; i < NumTotalRegs; i++)
	machine->WriteRegister(i, 0);

    // Initial program counter -- must be location of "Start"
    machine->WriteRegister(PCReg, 0);	

    // Need to also tell MIPS where next instruction is, because
    // of branch delay possibility
    machine->WriteRegister(NextPCReg, 4);

   // Set the stack register to the end of the address space, where we
   // allocated the stack; but subtract off a bit, to make sure we don't
   // accidentally reference off the end!
    machine->WriteRegister(StackReg, numPages * PageSize - 16);
    DEBUG('a', "Initializing stack register to %d\n", numPages * PageSize - 16);
}

//----------------------------------------------------------------------
// AddrSpace::SaveState
// 	On a context switch, save any machine state, specific
//	to this address space, that needs saving.
//
//	For now, nothing!
//----------------------------------------------------------------------

void AddrSpace::SaveState() 
{}

//----------------------------------------------------------------------
// AddrSpace::RestoreState
// 	On a context switch, restore the machine state so that
//	this address space can run.
//
//      For now, tell the machine where to find the page table.
//----------------------------------------------------------------------

void AddrSpace::RestoreState() 
{
    machine->pageTable = pageTable;
    machine->pageTableSize = numPages;
}

//----------------------------------------------------------------------
// SwapHeader
// 	Do little endian to big endian conversion on the bytes in the 
//	object file header, in case the file was generated on a little
//	endian machine, and we're now running on a big endian machine.
//----------------------------------------------------------------------

static void 
SwapHeader (NoffHeader *noffH)
{
	noffH->noffMagic = WordToHost(noffH->noffMagic);
	noffH->code.size = WordToHost(noffH->code.size);
	noffH->code.virtualAddr = WordToHost(noffH->code.virtualAddr);
	noffH->code.inFileAddr = WordToHost(noffH->code.inFileAddr);
	noffH->initData.size = WordToHost(noffH->initData.size);
	noffH->initData.virtualAddr = WordToHost(noffH->initData.virtualAddr);
	noffH->initData.inFileAddr = WordToHost(noffH->initData.inFileAddr);
	noffH->uninitData.size = WordToHost(noffH->uninitData.size);
	noffH->uninitData.virtualAddr = WordToHost(noffH->uninitData.virtualAddr);
	noffH->uninitData.inFileAddr = WordToHost(noffH->uninitData.inFileAddr);
}
/*
                                             ,-.
                                          _.|  '
                                        .'  | /
                                      ,'    |'
                                     /      /
                       _..----""---.'      /
 _.....---------...,-""                  ,'
 `-._  \                                /
     `-.+_            __           ,--. .
          `-.._     .:  ).        (`--"| \
               7    | `" |         `...'  \
               |     `--'     '+"        ,". ,""-
               |   _...        .____     | |/    '
          _.   |  .    `.  '--"   /      `./     j
         \' `-.|  '     |   `.   /        /     /
         '     `-. `---"      `-"        /     /
          \       `.                  _,'     /
           \        `                        .
            \                                j
             \                              /
              `.                           .
                +                          \
                |                           L
                |                           |
                |  _ /,                     |
                | | L)'..                   |
                | .    | `                  |
                '  \'   L                   '
                 \  \   |                  j
                  `. `__'                 /
                _,.--.---........__      /
               ---.,'---`         |   -j"
                .-'  '....__      L    |
              ""--..    _,-'       \ l||
                  ,-'  .....------. `||'
               _,'                /
             ,'                  /
            '---------+-        /
                     /         /
                   .'         /
                 .'          /
               ,'           /
             _'....----""""" 
*/
