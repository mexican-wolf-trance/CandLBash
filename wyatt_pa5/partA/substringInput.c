/*Charles Wyatt
 cs 2750
 11/19/17 */

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void substringInput(int argc , char *argv[])
{
	int j, false;

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
}
