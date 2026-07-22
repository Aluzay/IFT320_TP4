/* 
 * Programme pere pour compter le nombre de nombres premiers.
 * Divise la plage de nombres en portions et envoie le travail
 * en parallele a plusieurs instances de SubPrimeTest
 * Utilise write pour envoyer des parametres en utilisant
 * la table de communication inter-processus
 */

#include "syscall.h"

int
main()
{  
	int child;
	int res=0;
	child=Exec("../tp4test/SubPrimeTest",0,0);
	
	
	res+=Join(child);	
	
	
  	Exit(res);
    
}
