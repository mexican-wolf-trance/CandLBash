#include <stdio.h>
#include <stdlib.h>

int main ()
{
 FILE *f;

 f = fopen("numfile.txt","r");
 int i = 0, n = 0, d = 0;
 
 if (f==NULL)
  {
   printf("ERROR: Can't open\n");
   return 1;
  }

 printf("SUCCESS\n"); 

 while (!feof(f))
  {
    fscanf(f, "%d", &i);
    d += i;
    n++;
  }
 
 d /= n;
 
 printf("%d\n" , d);

 fclose(f);

return 0;
}
