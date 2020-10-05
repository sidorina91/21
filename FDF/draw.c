#include "fdf.h"

void	bresenham(t_xyz *xyz, t_map *map)
{
	init_xyz(xyz, map);
	point_z_zoom(xyz, map);
	point_rotation(xyz, map);
	point_proection2d(xyz, map);
	point_proection(xyz, map);
	point_zoom(xyz, map);
	motion(xyz, map);
	init_steps(xyz);
	while ((int)(xyz->x - xyz->x1) || (int)(xyz->y - xyz->y1))
	{
		if (xyz->x > 0 && xyz->y > 0 && xyz->x <= map->width
			&& xyz->y <= map->height)
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, xyz->x, xyz->y,
				get_color(xyz, map));
		xyz->x += xyz->step_x;
		xyz->y += xyz->step_y;
	}
}

void	init_sincos(t_map *map)
{
	map->sin_x = sin(map->angle_x);
	map->cos_x = cos(map->angle_x);
	map->sin_y = sin(map->angle_y);
	map->cos_y = cos(map->angle_y);
	map->sin_z = sin(map->angle_z);
	map->cos_z = cos(map->angle_z);
}

void	draw(t_map *map)
{
	int		x;
	int		y;
	t_xyz	*xyz;

	y = 0;
	xyz = (t_xyz*)ft_memalloc(sizeof(t_xyz));
	init_sincos(map);
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			bresenham_ready(xyz, map, x, y);
			x++;
		}
		y++;
	}
	ft_memdel((void**)&xyz);
	print_text(map);
}

void	bresenham_ready(t_xyz *xyz, t_map *map, int x, int y)
{
	if (x < map->cols - 1)
	{
		xyz->x = x;
		xyz->y = y;
		xyz->x1 = x + 1;
		xyz->y1 = y;
		bresenham(xyz, map);
	}
	if (y < map->rows - 1)
	{
		xyz->x = x;
		xyz->y = y;
		xyz->x1 = x;
		xyz->y1 = y + 1;
		bresenham(xyz, map);
	}
}
