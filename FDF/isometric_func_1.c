#include "fdf.h"

void	point_proection2d(t_xyz *xyz, t_map *map)
{
    float   tmp;
    if (map->proection_2d == 2)
	{
		tmp = xyz->x;
        xyz->x = -1 * xyz->y;
		xyz->y = tmp;
        tmp = xyz->x1;
		xyz->x1 = -1 * xyz->y1;
		xyz->y1 = tmp;
	}
    if (map->proection_2d == 3)
	{
		tmp = xyz->y;
        xyz->y = xyz->z;
		xyz->z = -1 * tmp;
        tmp = xyz->y1;
		xyz->y1 = xyz->z1;
		xyz->z1 = -1 * tmp;
	}
}