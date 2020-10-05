#include "fdf.h"

int		get_color(t_xyz *xyz, t_map *map)
{
	int z_new;
	int k;

	k = 0;
	z_new = 0;
	if (xyz->x1 - xyz->last_x != 0)
		z_new = ((xyz->x - xyz->last_x) * (xyz->z1_tmp - xyz->z_tmp)
			/ (xyz->x1 - xyz->last_x) + (xyz->z_tmp));
	if (z_new < 0)
		return (map->color * mod(z_new));
	else if (z_new > 0)
		return (map->color * z_new);
	else
		return (map->color);
}
