#include "fdf.h"

void	point_rotation(t_xyz *xyz, t_map *map)
{
	float	x_tmp;
	float	y_tmp;

	if (map->proection_2d > 0)
		return;
	y_tmp = xyz->y;
	xyz->y = xyz->y * map->cos_x - xyz->z * map->sin_x;
	xyz->z = y_tmp * map->sin_x + xyz->z * map->cos_x;
	x_tmp = xyz->x;
	xyz->x = xyz->x * map->cos_y - xyz->z * map->sin_y;
	xyz->z = x_tmp * map->sin_y + xyz->z * map->cos_y;
	x_tmp = xyz->x;
	xyz->x = xyz->x * map->cos_z + xyz->y * map->sin_z;
	xyz->y = (-1) * x_tmp * map->sin_z + xyz->y * map->cos_z;
	y_tmp = xyz->y1;
	xyz->y1 = xyz->y1 * map->cos_x - xyz->z1 * map->sin_x;
	xyz->z1 = y_tmp * map->sin_x + xyz->z1 * map->cos_x;
	x_tmp = xyz->x1;
	xyz->x1 = xyz->x1 * map->cos_y - xyz->z1 * map->sin_y;
	xyz->z1 = x_tmp * map->sin_y + xyz->z1 * map->cos_y;
	x_tmp = xyz->x1;
	xyz->x1 = xyz->x1 * map->cos_z + xyz->y1 * map->sin_z;
	xyz->y1 = (-1) * x_tmp * map->sin_z + xyz->y1 * map->cos_z;
}

void	motion(t_xyz *xyz, t_map *map)
{
	xyz->x += map->x0;
	xyz->y += map->y0;
	xyz->x1 += map->x0;
	xyz->y1 += map->y0;
}

void	point_zoom(t_xyz *xyz, t_map *map)
{
	xyz->x *= map->zoom;
	xyz->y *= map->zoom;
	xyz->x1 *= map->zoom;
	xyz->y1 *= map->zoom;
}

void	point_proection(t_xyz *xyz, t_map *map)
{
	if (map->proection && map->proection_2d == 0)
	{
		xyz->x = (xyz->x - xyz->y) * cos(map->isometr_angle);
		xyz->y = (xyz->x + xyz->y) * sin(map->isometr_angle) - xyz->z;
		xyz->x1 = (xyz->x1 - xyz->y1) * cos(map->isometr_angle);
		xyz->y1 = (xyz->x1 + xyz->y1) * sin(map->isometr_angle) - xyz->z1;
	}
}

void	point_z_zoom(t_xyz *xyz, t_map *map)
{
	xyz->z = xyz->z * map->zoom_z;
	xyz->z1 = xyz->z1 * map->zoom_z;
}
