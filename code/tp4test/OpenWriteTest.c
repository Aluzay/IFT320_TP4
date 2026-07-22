/* 
 * Test pour les fonctions Open et Write.
 * Cree un fichier RESULTAT_OPENWRITE_TEST dans le repertoire courant.
 * Ecrit 10x le message dans le fichier.
 * Facilement visible via la commande "cat" -> cat RESULTAT_OPENWRITE_TEST
 */

#include "syscall.h"

int
main()
{  
	
	int i=0;
	char* message = "Test pour Open et Write: _ \n";
	OpenFileId file;
	
	Create("RESULTAT_OPENWRITE_TEST");
	file = Open("RESULTAT_OPENWRITE_TEST");
	for (i=0;i<10;i++){
		
		message[25]=i+'0';
		Write(message, 29, file);	
	}
		
  	Exit(0);
    
}
