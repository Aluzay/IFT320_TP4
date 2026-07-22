/* 
 * Programme qui remplit un tableau avec des valeurs
 * et verifie ensuite si celles-ci sont intactes.
 * Trop grand pour la memoire, requiert des echanges de pages.
 */

#include "syscall.h"
#define SIZE 10001


char tablo[SIZE];

int main()
{  	
		
	int i;
	int err=0;
	Write ("Test remplissage\n",18,ConsoleOutput);
		
	for(i=0;i<SIZE;i++){		
		tablo[i]=(char)i;		
	}	
	for(i=0;i<SIZE;i++){		
		if(tablo[i]!=(char)i){
			err++;
		}
	}
  	Exit(err);    
}
