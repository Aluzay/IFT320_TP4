/* 
 * Test pour l'ecriture dans le journal systeme (SysCallLogWrite).
 * Devrait apparaitre a la console si l'option -d l est activee.
 */

#include "syscall.h"

int
main()
{  
	
	int i;
	char* message = "Test pour le journal: _ \n";
	
	for (i=0;i<10;i++){
		
		message[22]=i+'0';
		Write(message, 26, ConsoleOutput);	
	}
	
	
  	Exit(0);
    
}
