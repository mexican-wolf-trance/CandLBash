#include <stdio.h>
#include <stdlib.h>

double min(float a[] , double b)
{
	double g = a[0];
	for (int i = 0; i < b; i++)
	{
		if (a[i] < g)
		g = a[i];
	}
	return g;
}


