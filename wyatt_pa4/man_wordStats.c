#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void man_wordStats()
{
	FILE *f;
	char fileName[30];
	char n;
	int totC = 0, totL = 0, totW = 0;
	char pprev = '\n', prev = '\n';

	printf("Enter file name\n");
	scanf("%29s" , fileName);

	f = fopen(fileName , "r");
	if (f == NULL)
	{
		 printf("ERROR: Can't open %s\n" , fileName);
		 exit(1);
	}

	printf("%s successfully opened\n" , fileName);

        while((n = getc(f)) != EOF)
        {
                ++totC;
               	if(isspace(n))
                {
                        if(n == '\n')
                                ++totL;
                }
                else if(isspace(prev))
                        ++totW;

                pprev = prev;
                prev = n;
        }
        if(prev != '\n')
                ++totL;

	printf("Total characters = %d\n" , totC);
	printf("Total words = %d\n" , totW);
	printf("Total lines = %d\n" , totL);
}
