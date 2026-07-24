// addrspace.h 
//	Data structures to keep track of executing user programs 
//	(address spaces).
//
//	For now, we don't keep any information about address spaces.
//	The user level CPU state is saved and restored in the thread
//	executing the user program (see thread.h).
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#ifndef ADDRSPACE_H
#define ADDRSPACE_H

#include "copyright.h"
#include "filesys.h"
#include "noff.h"


#define UserStackSize		1024 	// increase this as necessary!

// Valeurs speciales utilisees lorsqu'une page n'est pas en memoire.
#define PAGE_IN_EXECUTABLE	-1
#define PAGE_IN_SWAP		-2



class AddrSpace {
  public:
    AddrSpace(OpenFile *executable);	// Create an address space,
					// initializing it with the program
					// stored in the file "executable"
    ~AddrSpace();			// De-allocate an address space

    void InitRegisters();		// Initialize user-level CPU registers,
					// before jumping to user code

    void SaveState();			// Save/restore address space-specific
    void RestoreState();		// info on a context switch 
	void PrintPageTable();
	void PrintPage(int,int);
	void handlePageFault(int page);
	
  private:
	void loadFromExecutable(int page, int frame);
	void swapIn(int page, int frame);
	void swapOut(int page);
	int selectVictim();

    TranslationEntry *pageTable;	// Assume linear page table translation
					// for now!
    int numPages;		// Number of pages in the virtual 
					// address space
    OpenFile *executableFile;	// Fichier executable pour le programme
    NoffHeader executableHeader;	// Entete du fichier executable pour le programme
	    char swapFileName[32];	// Nom unique du fichier d'echange du processus
	    OpenFile *swapFile;		// Fichier d'echange pour le programme
	    int nextVictim;		// Prochaine position de recherche d'une victime
	
};

#endif // ADDRSPACE_H
