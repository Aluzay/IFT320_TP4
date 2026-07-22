/* 
 * Programme enfant demarre par ExecTest.
 * Est assez grand pour causer des problemes s'il est mal charge en memoire.
 * Son affichage devrait se faire exclusivement apres ceux du parent.
 */

#include "syscall.h"

int
main()
{  	
	int i;
	Write("3-Programme enfant, fait apres le programme parent\n",52,ConsoleOutput);	
	Write("4-Boucle qui ecrapou\n",22,ConsoleOutput);	
	for(i=0;i<10;i++){
		Write("Cette boucle contient de l'ecrapou.\n",37,ConsoleOutput);
	}	
  	Exit(0);
    
}
