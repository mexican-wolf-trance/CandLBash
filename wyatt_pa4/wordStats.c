/*Charles Wyatt
 cs 2750
 11/05/17 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "cl_wordStat.h"
#include "man_wordStats.h"

int main (int argc , char *argv[])
{
	if (!argv[1])
		man_wordStats();
	else
		cl_wordStat(argc , argv);
	return 0;
}
