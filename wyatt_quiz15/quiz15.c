#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
	int status = 0, pid, x;
	int shmId, *shmPtr;
	key_t key;
	const int SIZE = 10;

	if((shmId = shmget(IPC_PRIVATE, SIZE*sizeof(int), IPC_CREAT | 0666)) < 0)
	{
		printf("shmget failed in parent\n");
    		exit(1);
	}
   	if ((shmPtr = (int *) shmat(shmId, NULL, 0)) == -1)
	{
    		printf("shmat failed in parent\n");
      		exit(2);
	}

	pid = fork();

	if(pid == 0)
	{
		printf("In child: Enter integer\n");
		scanf("%d", &x);
		shmPtr[0] = x;
		printf("%d Child dies\n", getpid());
		exit(0);

	}
	wait(&status);
	printf("Teh child's integer: %d\n", shmPtr[0]);
	shmdt(shmPtr);
	shmctl(shmId, IPC_RMID, NULL);
	wait(NULL);
return 0;
}
