#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int addInput(int argc , char *argv[])
{
	int r = 0;
        for (int i = 1; i < argc; i++)
        {
                if (isdigit(argv[i][0]))
                        r += atoi(argv[i]);
        }
	return r;
}
