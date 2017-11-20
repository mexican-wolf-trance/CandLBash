#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (int argc , char *argv[])
{
 for (int i = 0; i < argc; i++)
  printf("argv[%d] = %s (length = %zu)\n" , i, argv[i], strlen(argv[i]));
 return 0;
}  
