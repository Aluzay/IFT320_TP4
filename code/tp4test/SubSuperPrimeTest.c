/* 
 * Programme qui calcule le nombre de nombres premiers
 * dans un intervalle donne.
 * Le point de depart est obtenu via le parametre d'execution.
 */

#include "syscall.h"
#define SIZE 10000
#define MAXSQRT 2000


char sieve[SIZE];
int primes[MAXSQRT];
int start;
int end;


/*
	Fonction utilitaire pour convertir et imprimer un entier
	positif sur la console
*/

void strcat(char* src,char *dest, int pos,int size){
	int i;
	
	for(i=0;i<size;i++){	
		dest[i+pos]=src[i];
	}
}
int printd(unsigned int val,char* dest,int where){
	
	int i;
	char res[10];
	
	if(val==0){
	
		res[0]='0';
		strcat(res,dest,where,1);
		return 1;	
	}	
	
	i=0;
	while (val>0){
	
		i++;		
		res[10-i] = (val%10)+'0';
		val=val/10;		
	}
	strcat(res+(10-i),dest,where,i);

	return i;
}

int printPrefix(char* dest){

	int size;
	strcat("[",dest,0,1);	
	size=printd(start,dest,1);
	strcat(",",dest,size+1,size+1);
	size+=printd(end,dest,size+2);
	strcat("]--> ",dest,size+2,5);
	return size+7;
}
void printProgress(char* phase,int psize,int percent){
	
	int size;
	char res [30];
	size=printPrefix(res);
	strcat(phase,res,size,psize);
	strcat(":",res,size+psize,1);
	size+=printd(percent,res,size+psize+1);
	strcat("%\n",res,size+psize+1,2);
	Write(res,size+psize+3,ConsoleOutput);
}


int initPrimes(int sqrt){
	
	char temp[25];
	int i;
	int j;
	int p=0;
	int pid;
	int subsqrt;
	pid = Exec("../tp4test/SqrtTest",0,sqrt);	
	subsqrt=Join(pid)+1;
	sieve[0]=0;
	sieve[1]=0;
	sieve[2]=1;
		
	
	for(i=3;i<=sqrt;i+=2){	
		
		sieve[i]=1;
		sieve[i+1]=0;
	}	
	
	
	for (i=3;i<=subsqrt;i++){
	
		if(sieve[i]==1){
						
			for(j=i+i;j<sqrt;j+=i){
				sieve[j]=0;				
			}
		}
	}	
	
	for(i=1;i<=sqrt;i++){
		if(sieve[i]==1){
				
			primes[p]=i;
			p++;
		}
	}

	return p;
}


int main()
{  	
	int numPrimes;
	int pair=0;
	int impair=1;
	int total = 0;
	int pid;
	int i;
	int j;
	int sqrt;
	start = Read(0,0,ExecArgument);
	end=start+SIZE;
	
	pid = Exec("../tp4test/SqrtTest",0,end);	
	sqrt=Join(pid)+1;
	
	
	numPrimes = initPrimes(sqrt);	
	
	if(start%2==1){
		pair=1;
		impair=0;
	}	
	
	for(i=0;i<SIZE;i+=2){	
		if(i%1000==0){
			printProgress("Init",4,(i*100)/SIZE);
		}
		sieve[i]=pair;
		sieve[i+1]=impair;
	}	
	
	
	
	for (i=1;i<numPrimes;i++){

		int first;
					
		if(start%primes[i]==0) first=0;
		else first = (start/primes[i])*primes[i]+primes[i]-start;
		
		if (first+start==primes[i]) first+=primes[i];
			
		printProgress("Criblage",8,(i*100)/numPrimes);
		
		for(j=first;j<SIZE;j+=primes[i]){			
				
			sieve[j]=0;
		}
	}
	
	
	
	for(i=1;i<SIZE;i++){
	
		if(i%1000==0){			
			printProgress("Comptage",8,(i*100)/SIZE);
		}				
		total+=sieve[i];
	}	
	
  	Exit(total);    
}

/*
             _,........__
            ,-'            "`-.
          ,'                   `-.
        ,'                        \
      ,'                           .
      .'\               ,"".       `
     ._.'|             / |  `       \
     |   |            `-.'  ||       `.
     |   |            '-._,'||       | \
     .`.,'             `..,'.'       , |`-.
     l                       .'`.  _/  |   `.
     `-.._'-   ,          _ _'   -" \  .     `
`."""""'-.`-...,---------','         `. `....__.
.'        `"-..___      __,'\          \  \     \
\_ .          |   `""""'    `.           . \     \
  `.          |              `.          |  .     L
    `.        |`--...________.'.        j   |     |
      `._    .'      |          `.     .|   ,     |
         `--,\       .            `7""' |  ,      |
            ` `      `            /     |  |      |    _,-'"""`-.
             \ `.     .          /      |  '      |  ,'          `.
              \  v.__  .        '       .   \    /| /              \
               \/    `""\"""""""`.       \   \  /.''                |
                `        .        `._ ___,j.  `/ .-       ,---.     |
                ,`-.      \         ."     `.  |/        j     `    |
               /    `.     \       /         \ /         |     /    j
              |       `-.   7-.._ .          |"          '         /
              |          `./_    `|          |            .     _,'
              `.           / `----|          |-............`---'
                \          \      |          |
               ,'           )     `.         |
                7____,,..--'      /          |
                                  `---.__,--.'*/

