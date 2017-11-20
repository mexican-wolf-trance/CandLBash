#include <stdio.h>
#include <stdlib.h>

int main(int argc , char *argv[])
{
	printf("Enter the size of elements\n");
	int N=0 , m=0 , o=0;
	scanf("%d" , &N);

	int *array = (int*) malloc(N * sizeof(int));

	printf("Enter the numbers\n");
	for (int i = 0; i < N; i++)
	{
		scanf("%d" , &m);
		array[i] = m;
	}
	for (int i =0; i < N; i++)
	{
		o += array[i];
	}
	printf("%d\n" , o);


	free (array);
return 0;
}
