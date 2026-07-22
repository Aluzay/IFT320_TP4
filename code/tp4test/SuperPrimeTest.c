/* 
 * Programme pere pour compter le nombre de nombres premiers.
 * Divise la plage de nombres en portions et envoie le travail
 * en parallele a plusieurs instances de SubPrimeTest
 * 
 */

#include "syscall.h"
#define CHILDREN 15
#define RANGE 10000


int main()
{  
	int pids[CHILDREN];
	int i;
	int res=0;
	
	for (i=0;i<CHILDREN;i++){
		pids[i] = Exec("../tp4test/SubSuperPrimeTest",0,(i*RANGE)+2);
	}
	
	for(i=0;i<CHILDREN;i++){
		res+=Join(pids[i]);
	}	
  	Exit(res+1);    
    
}
