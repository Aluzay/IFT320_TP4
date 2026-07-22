/* 
 * Programme pere pour tester pour Join.
 * Demarre les programmes SubJoinTest1, SubJoinTest2, SubJoinTest3,SubJoinTest4,SubJoinTest5.
 * -Ce test doit etre execute avec l'algorithme de planification FCFS.
 * -La memoire doit etre correctement partageable (addrspace).
 * -Les pages physiques doivent etre reutilisables (dechargement de processus termines) 
 * -Le Join doit pouvoir attendre qu'un processus termine (mode bloque) et recuperer son code de sortie.
 * -Le Join doit pouvoir recuperer le code de sortie d'un processus qui a termine avant le Join (SubJoinTest5).
 */

#include "syscall.h"

int
main()
{  
	SpaceId child1,child2,child3,child4,child5;
	int res1,res2,res3,res4,res5;
	
	child1=Exec("../tp4test/SubJoinTest",10,0);
	child2=Exec("../tp4test/SubJoinTest2",20,0);
	
	
	Write("Join me and I will complete your training.  With our combined strength, we can end this destructive conflict and bring order to the galaxy.\n",141,ConsoleOutput);
	res1=Join(child1);	
	if(res1==42){	
	
		child3=Exec("../tp4test/SubJoinTest3",30,0);
		Write("If you only knew the power of the dark side.  Obi-Wan never told you what happened to your father.\n",100,ConsoleOutput);	
		res2=Join(child2);
		
		if(res2==34){
			Write("No.  I am your father.\n",24,ConsoleOutput);	

			res3=Join(child3);
			
			if(res3==110)
			{
				child4=Exec("../tp4test/SubJoinTest4",30,0);
				Write("Search your feelings.  You know it to be true.\n",48,ConsoleOutput);
				res4=Join(child4);
				if(res4==12){
					child5=Exec("../tp4test/SubJoinTest5",30,0);					
					Write("Luke.  You can destroy the Emperor. He has foreseen this.  It is your destiny.  Join me, and together we can rule the galaxy as father and son.  Come with me.  It is the only way.\n",181,ConsoleOutput);
					Yield();
					res5=Join(child5);					
					if(res5==9){
						Write("It's a Wrap!!!\n",16,ConsoleOutput);
					}
				}
				else{
					Write("Cut!!!!\n",9,ConsoleOutput);
				}
			}
			else{
				Write("Cut!!!\n",8,ConsoleOutput);
			}
		}
		else{
			Write("Cut!!\n",7,ConsoleOutput);
		}
	}
	
	else{
		Write("Cut!\n",6,ConsoleOutput);
	}
	
  	Exit(0);
    
}
