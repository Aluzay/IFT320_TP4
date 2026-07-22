// exception.cc 
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.  
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "syscall.h"

//IFT320: includes utiles
#include "openfile.h"
#include "addrspace.h"



//IFT320: fonctions utiles
extern void StartProcess(char *filename);
int SysCallRead(OpenFile*, int,int,int);
int SysCallWrite(OpenFile*, int,int,int);
void CopyFromUser(char *,char *,int);
void CopyToUser(char *,char *,int);





//----------------------------------------------------------------------
// ExceptionHandler
// 	Entry point into the Nachos kernel.  Called when a user program
//	is executing, and either does a syscall, or generates an addressing
//	or arithmetic exception.
//
// 	For system calls, the following is the calling convention:
//
// 	system call code -- r2
//		arg1 -- r4
//		arg2 -- r5
//		arg3 -- r6
//		arg4 -- r7
//
//	The result of the system call, if any, must be put back into r2. 
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//	"which" is the kind of exception.  The list of possible exceptions 
//	are in machine.h.
//----------------------------------------------------------------------

void ExceptionHandler(ExceptionType which)
{
    int type = machine->ReadRegister(2);

    
    switch (which)
    {	    
       case SyscallException:
		{
			DEBUG('e',"Traitement de l'appel systeme : ");
			int par1 = machine->ReadRegister(4); 
			int par2 = machine->ReadRegister(5); 
			int par3 = machine->ReadRegister(6); 
			char nom[100];                        
			char * tampon;
			int code;
			    
			switch (type) {
        	 
			case SC_Halt:   {
    		 
					DEBUG('a', "Shutdown, initiated by user program.\n");
					interrupt->Halt();
					break;
				        } 
			case SC_Exit:
					{
                                         DEBUG('z',"Exit %d,0x%x\n", par1,(int)currentThread);
        	                         delete currentThread->space;
	
                                        Thread* parent = currentThread->getParent();
					if(parent!=NULL){
						parent->SetEndCode((SpaceId)currentThread,currentThread->pid,par1);
						parent->WakeUp();
					}						
					//IFT320: pour les stats
					currentThread->stats->setExitCode(par1);
        	                        currentThread->Finish();
        	                        ASSERT(FALSE);
        	                        break;
				       }	
			case SC_Exec:
        	        {	char * nom1 = new char[100];
						
						CopyFromUser(nom1, (char *) par1,  -1);						
						Thread *tmp = new Thread(nom1, par2);	
						DEBUG('z',"Exec (0x%x)\n",(int)tmp);	
				
						tmp->setParent(currentThread);	
						tmp->setArgv(par3);						
						currentThread->AddChild((SpaceId)tmp,tmp->pid);	
						DEBUG('z',"ExecArg:%d, %s(0x%x)\n",par3,currentThread->getName(),(int)currentThread);	
				
						//Fork doit etre fait apres toutes les initialisations
						//de l'objet thread parce qu'il peut causer un
						//changement de contexte.
						tmp->Fork((VoidFunctionPtr)StartProcess,(int)nom1); 
						machine->WriteRegister(2,(SpaceId)tmp);						
        	        }
        	        break;
			case SC_Join:
			{
        	        SpaceId id = machine->ReadRegister(4);	
					DEBUG('z',"Join for: (0x%x) -> (0x%x)\n",(int) currentThread,id);					
					code = currentThread->Join(id,((Thread*)id)->pid);	
					DEBUG('z',"Joined:%d, (0x%x) -> (0x%x)\n",code,(int) currentThread,id);									
					machine->WriteRegister(2,code);				
        	        break;
			}	
			case SC_Create:
			{
        	        CopyFromUser(nom, (char *) par1,  -1);
        	        DEBUG('e',"Creation du fichier %s\n", nom);
        	        code = fileSystem->Create(nom,  20 /*par2*/);
        	        machine->WriteRegister(2,code);
        	        break;
					
			case SC_Open:
        	        CopyFromUser(nom, (char*) par1, -1);
        	        DEBUG('e',"Ouverture du fichier %s\n", nom);					
        	        code = (int) fileSystem->Open(nom);
					if(code==NULL){
						printf("Open FAIL; filename:\n%s\n",nom);
						ASSERT(FALSE);
					}
        	        machine->WriteRegister(2,code);
        	        break;
			}		
			case SC_Read:
				  {	DEBUG('e',"Read\n");	
					if(par3 == ExecArgument){
						code = currentThread->getArgv();
						DEBUG('z',"Argv:%d, %s(0x%x)\n",code,currentThread->getName(),(int)currentThread);						
					}
					else{					
						code = SysCallRead((OpenFile*)par3,par1,par2,-1);
					}
					machine->WriteRegister(2,code);
					break;
				   } 
			case SC_Write:
				   {	
                                       DEBUG('e',"Write\n");
					tampon = new char[par2+1];
					
					CopyFromUser(tampon, (char *)par1, par2);
					if (par3 != ConsoleOutput)
						code = ((OpenFile *)par3)->Write(tampon, par2);
					else {
						tampon[par2]=0;
						DEBUG('l',"%s",tampon);
					}
        	                       machine->WriteRegister(2,code);
        	                        break;
				  } 
			case SC_Yield:
				       {	DEBUG('e',"Yield\n");
					currentThread->Yield();
					break;
				   } 
			default :    {    	 
					printf("Unexpected System call %d\n", type);
					ASSERT(FALSE);
	                              }	
                 }
		
		int pc;
		pc = machine->ReadRegister(PCReg);
		machine->WriteRegister(PrevPCReg,pc);
		pc = machine->ReadRegister(NextPCReg);
		machine->WriteRegister(PCReg,pc);
		pc+=4;
		machine->WriteRegister(NextPCReg,pc);
	    
		break;
    }	
    
    case PageFaultException:
	{
    	currentThread->stats->incPageFaults();
    	int page = machine->ReadRegister(BadVAddrReg) / PageSize;
    	printf("Faute de pages : %d\n", page);
    	currentThread->Finish();
    	ASSERT(FALSE);
    	break;
	}
			
	    case ReadOnlyException:
		    printf("Tentative d'ecriture dans une page non modifiable. \n");
			currentThread->stats->setExitCode(-ReadOnlyException);
		    currentThread->Finish();	            
		    break;
			
	    case BusErrorException:
		    printf("Erreur d'alignement. \n");
			currentThread->stats->setExitCode(-BusErrorException);
		    currentThread->Finish();	            
		    break;
			
	    case AddressErrorException:
		    printf("Thread %s(0x%x)[%d], Erreur d'adressage:0x%x . \n",currentThread->getName(),(int)currentThread,currentThread->getArgv(),machine->ReadRegister(BadVAddrReg));
		    printf("PC:0x%x\n",machine->ReadRegister(PCReg));
			currentThread->space->PrintPageTable();			
			currentThread->stats->setExitCode(-AddressErrorException);			
			currentThread->Finish();			
		    break;
			
	    case IllegalInstrException:
		    printf("Instruction invalide. \n");
			currentThread->stats->setExitCode(-IllegalInstrException);
		    currentThread->Finish();	            
		    break;
			
		 case OverflowException:
		    printf("Debordement arithmetique. \n");		    	            
		    break;
			
	    case NoException:
		    printf("No Exception ");
		    ASSERT(FALSE);
		    break;
	    
		default :		    
		    printf("Unexpected user mode exception %d\n", which);
		    ASSERT(FALSE);
		    break;
    }

}




int SysCallRead(OpenFile* src, int vaddr,int size,int offset){
	
	char* buffer = new char[size];
	
	int code;
	if(offset==-1){
		code = src->Read(buffer,size);
	}
	else{
		code = src->ReadAt(buffer,size,offset);
	}

	
	CopyToUser((char*)vaddr,buffer,size);
	
	delete[] buffer;
	return code;
}
int SysCallWrite(OpenFile* dest, int vaddr,int size,int offset){
	
	char* buffer = new char[size];
	CopyFromUser(buffer,(char*)vaddr,size);
	int code;
	if(offset==-1){
		code = dest->Write(buffer,size);
	}
	else{
		code = dest->WriteAt(buffer,size,offset);
	}	
	
	delete[] buffer;
	return code;

}





void CopyFromUser(char * dest, char * source, int longueur)
{
	int i = 0;
	int tmp;
	int code;
	
	if (longueur >= 0)
		for (i=0 ; i < longueur ; i++) {		
				code = machine->ReadMem((int)source+i, 1, &tmp);
				
				dest[i] = (char)tmp;				
		}
	else
	{	
		do {
			code = machine->ReadMem((int) source+i, 1, &tmp);
			
			dest[i] = (char)tmp;			
			i++;
		}while (dest[i-1] != 0);
	}
}

void CopyToUser(char * dest, char * source, int longueur)
{
	int code;
	for (int i=0; i < longueur; i++){
			code = machine->WriteMem((int)dest+i, 1, (int)source[i]);
			
		}
	
}


