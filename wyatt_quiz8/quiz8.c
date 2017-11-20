#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc , char *argv[])
{
 int i;
 int j = 1;
 int k;
 if (argv[1] == '\0')
 {  
   printf("You need uh argument\n");
 }
 else
 {
  int n = atoi(argv[1]);
  k = n;
  for (i=0; i<k; i++)
  {
   j *= n;
   n--;
  }
  printf("%d\n" , j);
 }
return 0;
}
