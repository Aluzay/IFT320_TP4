/* 
 * Test pour Priorite dynamique.
 * Tous les programmes devraient arriver a terminer malgre la boucle 
 * infinie qui est tres prioritaire
 * etre visibles, SubPriorityTest2 n'aura jamais l'UCT.
 * Ce test doit etre execute avec l'algorithme de planification HRN (3). 
 * Les valeurs de priorite les plus basses ont la plus haute priorite.
 */

#include "syscall.h"

int
main()
{  
	
	Write("1-Programme parent debut\n",26,ConsoleOutput);	
	Exec("../tp4test/SubHrnTest",10,0);
	Exec("../tp4test/Bouclalinfini",20,0);	
	Exec("../tp4test/SubHrnTest2",30,0);
	Exec("../tp4test/SubHrnTest3",40,0);
	
	Write("2-Programme parent fin\n",24,ConsoleOutput);
	
  	Exit(0);
    
}
