/* 
 * Test pour Exec, avec remplissage memoire.
 * Demarre le programme SubFullTest.
 * Les affichages de ce programme et de SubFullTest devraient
 * apparaitre exclusivement dans l'ordre numerote.
 * -Ce test doit etre execute avec l'algorithme de planification FCFS.
 * -Ce test ne peut fonctionner que si addrspace.cc est correctement modifie
 * -Les pages physiques doivent pouvoir etre reutilisees lorsqu'un processus termine.
 */

#include "syscall.h"

int
main()
{  
	
	Write("1-Programme grand-parent, debut\n",33,ConsoleOutput);
	
	Exec("../tp4test/SubFullTest",10,0);
	
	Write("2-Programme grand-parent, fin\n",31,ConsoleOutput);
	
  	Exit(0);
    
}
