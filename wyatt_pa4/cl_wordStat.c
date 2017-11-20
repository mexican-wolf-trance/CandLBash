#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void cl_wordStat(int argc , char *argv[])
{
	FILE *f;
	char n;
	int totC = 0, totL = 0, totW = 0;
	int totalC = 0, totalL = 0, totalW = 0;
	char pprev = '\n', prev = '\n';

	for (int i = 1; i < argc; i++)
	{
		totC = 0; totW = 0; totL = 0;
		f = fopen(argv[i] , "r");
		if (f == NULL)
		{ printf("ERROR: Can't open\n"); exit(1); }

		printf("%s successfully opened\n" , argv[i]);

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
	totalC += (totC); totalW += (totW); totalL += (totL);
	printf("Total characters = %d\n" , (totC));
        printf("Total words = %d\n" , (totW));
        printf("Total lines = %d\n\n" , (totL));
	}
	if (argc > 2)
        	printf("Overall totals: %d characters, %d words, %d lines\n" , totalC , totalW , totalL);
}
