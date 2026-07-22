/* 
 * Test pour les fonctions Read et Write.
 * Ouvre le fichier NE_PAS_EFFACER et recupere la phrase qui s'y trouve, pour
 * finalement l'afficher 10x dans le journal systeme. La phrase est recuperee en 15 parties.
 * Le resultat est dans le fichier RESULTAT_READWRITE_TEST. Affichable avec la commande "cat".
 */

#include "syscall.h"

int
main()
{  
	
	int i,j;
	char transfert[5];
	OpenFileId source;
	OpenFileId destination;	
	
	source = Open("NE_PAS_EFFACER");
	Create("RESULTAT_READWRITE_TEST");
	destination=Open("RESULTAT_READWRITE_TEST");	
	
	for (i=0;i<10;i++){		
		source = Open("NE_PAS_EFFACER");
		
		for(j=0;j<15;j++){
			Read(transfert,5,source);		
			Write(transfert,5, destination);
		}			
	}
	
  	Exit(0);
    
}
