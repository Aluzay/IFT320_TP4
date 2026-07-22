/* 
 * Test pour la fonction Read.
 * Ouvre le fichier NE_PAS_EFFACER et recupere la phrases qui s'y trouve, pour
 * finalement l'afficher 10x dans le journal systeme.
 * Doit etre execute avec l'option nachos -d l pour voir les messages du journal.
 */

#include "syscall.h"

int
main()
{  
	
	int i=0;
	char message[76];
	OpenFileId file;
	
	
	file = Open("NE_PAS_EFFACER");
	Read(message,75,file);
	for (i=0;i<10;i++){		
		message[75]=i+'0';
		Write(message,76, ConsoleOutput);	
	}
	
  	Exit(0);
    
}
