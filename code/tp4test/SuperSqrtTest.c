/* 
 * Programme qui calcule la somme des racines carrees
 * des multiples de 10 inferieurs a 100: 3+4+5+6+7+7+8+8+9+10 = 67
 */

#include "syscall.h"
#define SIZE 10 
int main()
{  	
	int pids[SIZE];
	int i;
	int res=0;
	
	for (i=0;i<SIZE;i++){
		pids[i] = Exec("../tp4test/SqrtTest",0,(i+1)*10);
	}
	
	for(i=0;i<SIZE;i++){
		res+=Join(pids[i]);
	}	
  	Exit(res);    
}
