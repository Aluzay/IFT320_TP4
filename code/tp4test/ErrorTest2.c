/*
Test Erreur 2 : Address Error
*/

#include "syscall.h"

int
main()
{
	int *a,b;
	char *x,y;

  
	x = &y;
	x++;
	a = (int * )x;
	b = *a;    
}
