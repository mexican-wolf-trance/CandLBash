#include <stdio.h>
#include <stdlib.h>

double sum(float a[] , double b)
{	
	double d;
	for (int i = 0; i < b; i++)
		d += a[i];
 	return d;
}


