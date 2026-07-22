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
	for(i=0;i<10;i++){
		Write("Ce programme ne devrait pas prendre l'UCT\n",43,ConsoleOutput);
	}	
  	Exit(0);
    
}
