/* 
 * Test pour Exec.
 * Demarre le programme SubExecTest.
 * Les affichages de ce programme et de SubExecTest devraient
 * apparaitre exclusivement dans l'ordre numerote.
 * Ce test doit etre execute avec l'algorithme de planification FCFS.
 * Ce devrait fonctionner meme si addrspace.cc n'est pas modifie.
 */

#include "syscall.h"

int
main()
{  
	
	Write("1-Programme parent avant l'exec\n",33,ConsoleOutput);
	
	Exec("../tp4test/SubExecTest",10,0);
	
	Write("2-Programme parent apres l'exec\n",33,ConsoleOutput);
	
  	Exit(0);
    
}
