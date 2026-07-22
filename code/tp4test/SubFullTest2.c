/* 
 * Programme enfant demarre par SubFullTest.
 * Lache l'UCT pour permettre aux autres programmes de se charger
 * et remplir la memoire.
 * 
 */

#include "syscall.h"

int
main()
{  	
	int i;
	Write("4-Programme enfant, apres chargement\n",38,ConsoleOutput);	
	Yield();
	for(i=0;i<5;i++){
		Write("6-Programme enfant, corps de la boucle.\n",41,ConsoleOutput);
	}	
  	Exit(0);
    
}
