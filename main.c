#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main (int argc , char *argv[])
{
	if (!argv[1]) { printf("Need arguments\n"); return 1; }

	int j, k = 0, r = 0, false;

	for (int i = 1; i < argc; i++)
	{
		if (isdigit(argv[i][0]))
			r += atoi(argv[i]);
	}

	printf("Total integers: %d\n" , r);

	for (int i = 1; i < argc; i++)
	{
		if (isdigit(argv[i][0]))
			false = 0;
		else
		{
			for (j = 1; j < argc; j++)
			{
				if ((strcmp(argv[i] , argv[j]) != 0) && (strcasestr(argv[j] , argv[i]) != NULL))
					printf("%s is a substring of %s\n" , argv[i], argv[j]);
			}
		}
	}
return 0;
}
