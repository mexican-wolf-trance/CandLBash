#include <stdio.h>
#include <stdlib.h>

void main()
{
	FILE *p;
	p = fopen("child.txt" , "a");
	int n = 9, z = 0; z = n*n;
	fprintf(p , " %d quared is %d\n" , n, z);
}
