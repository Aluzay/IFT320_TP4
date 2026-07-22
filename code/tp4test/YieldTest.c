/* 
 * Test pour Exec.
 * Demarre le programme SubExecTest.
 * Les affichages de ce programme et de SubExecTest devraient
 * apparaitre exclusivement dans l'ordre 1-3-4-ecrapous-2.
 * Ce test doit etre execute avec l'algorithme de planification FCFS.
 * Ce test ne peut fonctionner que si addrspace.cc est modifie correctement.
 */

#include "syscall.h"

int
main()
{  
	
	Write("1-Programme parent avant l'exec\n",33,ConsoleOutput);
	
	Exec("../tp4test/SubExecTest",10,0);
	Yield();
	
	Write("2-Programme parent apres l'exec\n",33,ConsoleOutput);
	
  	Exit(0);
    
}
