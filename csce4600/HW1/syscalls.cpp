#include <sys/types.h> 
#include <sys/wait.h>
#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv)
{

pid_t procc;

    /* fork a child process */
    procc = fork();

if (procc < 0) 
{ 		/* error */ 
	fprintf(stderr, "Fork Failed"); 
	return 1;
}

else if (procc == 0) 
{ 		/* child process */
 
     	execlp("/bin/ls","ls",NULL); /*exectues child process to do ls*/
}

else 
{ 	/* parent process */

      	/* parent will wait for the child to complete */
      	wait(NULL);
      	printf("Child Complete\n");
	printf("process ID is %d\n", getpid());
	printf("parent process ID is %d\n", getppid());
}

while(1)
{
	char line;
	int i;
	
	printf("press k to kill the process: ");	
	scanf("%c",&line);

	if(!isalpha(line)) 		/*checks for an alphabetic character*/
               printf("error");

	else if(line == 'k' || line == 'K')
	kill(procc, SIGQUIT);		/*signals proccess to quit if still running*/
	printf("\n...done\n");
	exit(0);
}

return 0;
}

