/* 
 * Test pour Priorite statique.
 * Demarre les programmes SubPriorityTest, SubPriorityTest, Bouclalinfini.
 * Seuls les affichages de ce programme et de SubpriorityTest devraient
 * etre visibles, SubPriorityTest2 n'aura jamais l'UCT.
 * Ce test doit etre execute avec l'algorithme de planification priorite (2). 
 * Les valeurs de priorite les plus basses ont la plus haute priorite.
 */

#include "syscall.h"

int
main()
{  
	
	Write("1-Programme parent debut\n",26,ConsoleOutput);
	
	Exec("../tp4test/SubPriorityTest",10,0);
	Exec("../tp4test/Bouclalinfini",20,0);
	Exec("../tp4test/SubPriorityTest2",30,0);
	
	
	Write("2-Programme parent fin\n",24,ConsoleOutput);
	
  	Exit(0);
    
}
