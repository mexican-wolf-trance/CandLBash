#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "addInput.h"
#include "substringInput.h"

int main (int argc , char *argv[])
{
	if (!argv[1]) { printf("Need arguments\n"); return 1; }

	printf("Total integers: %d\n" , addInput(argc , argv));

	substringInput(argc , argv);

return 0;
}
