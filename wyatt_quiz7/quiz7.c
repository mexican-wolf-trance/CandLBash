#include <stdio.h>

int main ()
{
  int a;
  int b;
  int c;

  printf( "input two numbers\n" );
  scanf("%d %d" , &a , &b);

  c = a + b;

  printf( "%d\n" , c );

  return 0;
}
