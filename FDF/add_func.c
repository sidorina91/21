#include "fdf.h"

void	init_steps(t_xyz *xyz)
{
	float tmp;

	xyz->step_x = xyz->x1 - xyz->x;
	xyz->step_y = xyz->y1 - xyz->y;
	tmp = max(mod(xyz->step_x), mod(xyz->step_y));
	xyz->step_x /= tmp;
	xyz->step_y /= tmp;
	xyz->last_x = xyz->x;
}

void	init_xyz(t_xyz *xyz, t_map *map)
{
	xyz->z = map->matrix[(int)xyz->y][(int)xyz->x];
	xyz->z1 = map->matrix[(int)xyz->y1][(int)xyz->x1];
	xyz->z_tmp = xyz->z;
	xyz->z1_tmp = xyz->z1;
}
