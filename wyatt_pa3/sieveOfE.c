#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc , char *argv[])
{
	if (argv[1] == '\0')
		printf("Arguments please\n");
	else
	{
		int N = atoi(argv[1]);
		int i, j = 0, arr[N];
		for (i = 2; i < N; i++)
	 	{
 			arr[j] = i;
 			j++;
		}
   		for (i = 0; i < N-2; i++)
		{
			if (arr[i] != -1)
				for (j = 2*arr[i]-2; j < N-2; j+=arr[i])
					arr[j] = -1;
		}
		for (i = 0; i < N-2; i++)
		{
			if (arr[i] != -1)
				printf("%d\n" , arr[i]);
		}
	}
	return 0;
}
  
