#include <stdlib.h>
#include <stdio.h>

int main (int argc , char *argv[])
{
 if (argv[1] == '\0')
  printf("You need argument!\n");
 else
 {
  printf("%d\n" , square(argv[1]));
  printf("%d\n" , cube(argv[1]));
 }
 return 0;
}
