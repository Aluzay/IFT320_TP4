/* 
 * Programme parent pour Yield test plus approfondi.
 * Ne peut fonctionner que si deux processus peuvent partager 
 * correctement la memoire.
 * Devrait sortir Dude! et Sweet! en alternance.
 */

#include "syscall.h"

int
main()
{  
	
	int i;	
	Exec("../tp4test/SubYieldTest2",10,0);
	
	for(i=0;i<10;i++){
		Write("Dude!\n",7,ConsoleOutput);
		Yield();
	}	
  	Exit(0);
    
}
