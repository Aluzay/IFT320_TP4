/* 
 * Programme pere pour tester pour Join.
 * Demarre le programme SubMiniJoinTest et recupere son code d'erreur.
 * Ce test doit etre execute avec l'algorithme de planification FCFS.
 */

#include "syscall.h"

int
main()
{  
	SpaceId child;
	int res;
	
	child=Exec("../tp4test/SubMiniJoinTest",10,0);
	Write("Parent avant join\n",19,ConsoleOutput);
	
	res=Join(child);	
	if(res==99){	
	
		Write("Test reussi!\n",14,ConsoleOutput);	
	}
	else{
		Write("Test echoue!\n",14,ConsoleOutput);
	}
	
  	Exit(0);
    
}
