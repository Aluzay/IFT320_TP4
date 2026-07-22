/* 
 * Programme qui calcule la valeur entiere 
 * inferieure ou egale a la racine carree.
 * Peut recevoir un parametre a l'execution
 * Le parametre est obtenu avec Write, et
 * le OpenFileID special "ExecArgument".
 * Si l'argument a la valeur par defaut (0)
 * alors la macro N sera utilisee.
 */

#include "syscall.h"
#define N 4587603


int sqrt(int n){
	return sqrtrec(n,2);	
}

int sqrtrec (int n, int r){

	
	int cofactor = n/r;
	int delta = cofactor-r;
	int small=r;
	if(delta==0) return r;
	if(delta<0){
		delta=-delta;
		small=cofactor;
	}	
	if(delta==1){ return small;}	
	else{	
		return sqrtrec(n,(r+cofactor)/2);
	}
}
int main()
{  	
	int arg=Read(0,0,ExecArgument);
	int res;
	if(arg!=0){	
		res = sqrt(arg);
	}
	else{
		res=sqrt(N);
	}
  	Exit(res);    
}
