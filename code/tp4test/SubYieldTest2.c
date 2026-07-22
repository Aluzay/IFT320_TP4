/* 
 * Pogramme parent pour Yield test plus approfondi.
 * Ne peut fonctionner que si deux processus peuvent partager 
 * correctement la memoire.
 * Devrait sortir Dude! et Sweet! en alternance.
 */

#include "syscall.h"

int
main()
{  
	
	int i;
	
	
	for(i=0;i<10;i++){
		Write("Sweet!\n",8,ConsoleOutput);
		Yield();
	}	
  	Exit(0);
    
}
