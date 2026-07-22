/*
Test Erreur 3 : Address Error
*/

#include "syscall.h"

int
main()
{
	int *a,b,c; 
 	
 	a=999999999;
 	b=0;
 	c=0;
 	
  
	*a = 10;
	Exit(5);
    
}
