/* 
 * Programme enfant demarre par FullTest. Demarre plusieurs instances de
 * SubFullTest2 et leur permet de prendre l'UCT apres.
 * La memoire physique devrait etre presque pleine avec ce test.
 * Les pages physiques utilisees par le premier processus (FullTest)
 * doivent etre reutilisees pour que ce test fonctionne.
 */

#include "syscall.h"

int
main()
{  	
	int i;
	Write("3-Parent du milieu, debut\n",60,ConsoleOutput);	
	
	for(i=0;i<3;i++){
		Exec("../tp4test/SubFullTest2",10,0);		
	}	
	Yield();
	
	Write("5-Parent du milieu, fin\n",58,ConsoleOutput);	
	
  	Exit(0);
    
}
