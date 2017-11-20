#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	int status;
    	int pid;
	FILE *p;
    	pid=fork();


    	if(pid != 0)
   	{
        	wait(&status);
	}
	else if(pid==0)
    	{
        	p = fopen("child.txt" , "a+");
		fprintf(p, "\n Hello I am the child process ");
        	fprintf(p, "\n My pid is %d and ppid is %d\n\n", getpid() ,getppid());
		execl("/accounts/students/c/cwdh4/wyatt_quiz14/sqr" , "/accounts/students/c/cwdh4/wyatt_quiz14/sqr" , (char*)NULL, (char*)NULL);
		fclose(p);
    	}
	else
		return 1;
return 0;
}
