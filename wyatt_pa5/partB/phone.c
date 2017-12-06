/*Charles Wyatt
 cs 2750
 11/19/17 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "phone_fmt.h"

int main(int argc , char *argv[])
{
	if (!argv[1]) { printf("Need arguments\n"); return 1; }

	phone_fmt(argc, argv);
	/*int r = 0, k, len = 0;

	for (int i = 1; i < argc; i++)
	{
		len = strlen(argv[i]);
		int *array = (int*) malloc(len * sizeof(int));
		if (array == NULL) {fputs ("Memory error" , stderr); exit(2);}

		k = 0;
		for (int j = 0; j < len; j++)
		{
			if (isdigit(argv[i][j]))
			{
				r = argv[i][j] - '0';
				array[k] = r;
				k++;
			}
		}
		len = sizeof(array) / sizeof(array[0]);
		if (len < 10) { printf("ERROR: Not enough digits on input!\n"); return -1; }

		printf("(%d%d%d) %d%d%d-%d%d%d%d\n" , array[0], array[1], array[2], array[3], array[4], array[5], array[6], array[7], array[8], array[9]);
		free(array);
	}*/
return 0;
}
