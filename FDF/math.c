#include "fdf.h"

float	max(float n1, float n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

float	min(float n1, float n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

float	mod(float n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}
