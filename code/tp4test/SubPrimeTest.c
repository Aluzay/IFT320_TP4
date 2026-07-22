/* 
 * Programme qui calcule le nombre de nombres premiers
 * dans un intervalle donne.
 * l'intervalle est obtenu via le systeme de communication inter-processus
 */

#include "syscall.h"
#define SIZE 100001
#define SQRT 317

char sieve[SIZE];


int main()
{  	
	int total = 0;
	
	int i;
	int j;
	
	Write ("Nombres premiers precedent N\n",32,ConsoleOutput);
	sieve[0]=0;
	sieve[1]=0;
	sieve[2]=1;
	Write ("Initialisation...",18,ConsoleOutput);
	for(i=3;i<SIZE;i+=2){	
		if(i%1001==0){
			Write(".",2,ConsoleOutput);
		}
		sieve[i]=1;
		sieve[i+1]=0;
	}	
	Write ("\nCriblage...",13,ConsoleOutput);
	for (i=3;i<=SQRT;i++){
		if(sieve[i]==1){
			Write(".",2,ConsoleOutput);			
			for(j=i+i;j<SIZE;j+=i){
				sieve[j]=0;
			}
		}
	}
	
	Write ("\nVerification...",17,ConsoleOutput);
	for(i=1;i<SIZE;i++){			
		if(i%1000==0){
			Write(".",2,ConsoleOutput);
		}
		total+=sieve[i];
	}	
	Write("\n",2,ConsoleOutput);
  	Exit(total);    
}
