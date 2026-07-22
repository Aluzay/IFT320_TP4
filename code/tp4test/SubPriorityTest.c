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
		Write("3-Programme enfant prioritaire\n",32,ConsoleOutput);	
	}	
  	Exit(0);
    
}
