/* 
 * Test pour la creation de fichier.
 * Un fichier avec le nom RESULTAT_CREATE_TEST devrait
 * apparaitre dans le repertoire courant, avec la taille 0.
 */

#include "syscall.h"

int
main()
{  
	
	Create("RESULTAT_CREATE_TEST");	
	
  	Exit(0);
    
}
