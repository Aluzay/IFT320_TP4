/*
Test Erreur 3 : Illegal instruction (division par 0)
*/

#include "syscall.h"

int
main()
{
	int a,b,c;
 
 	a=0;
 	b=10;
 	c=0;
 	
  
	c = b/a;
    
}
