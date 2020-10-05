#include "fdf.h"

void	zoom_key(int key, t_map *map)
{
	float step;

	step = 200 / (float)map->cols;
	if (key == 78)
	{
		map->zoom -= step;
		map->zoom_z = map->zoom_z * map->zoom / (map->zoom + step);
	}
	if (key == 69)
	{
		map->zoom += step;
		map->zoom_z = map->zoom_z * map->zoom / (map->zoom - step);
	}
}

void	zoom_z_key(int key, t_map *map)
{
	float step;

	step = (float)(map->z_max - map->z_min) / 1000;
	if (key == 43)
		map->zoom_z -= step;
	if (key == 47)
		map->zoom_z += step;
}

void	window_key(t_map *map)
{
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	map_create(map);
	draw(map);
	mlx_hook(map->win_ptr, 2, 0, deal_key, map);
	mlx_loop(map->mlx_ptr);
}

void	xy_key(int key, t_map *map)
{
	if (key == 126)
		map->y0 -= 10;
	if (key == 125)
		map->y0 += 10;
	if (key == 123)
		map->x0 -= 10;
	if (key == 124)
		map->x0 += 10;
}

int		deal_key(int key, t_map *map)
{
	rotate_key(key, map);
	zoom_key(key, map);
	zoom_z_key(key, map);
	xy_key(key, map);
	exit_key(key, map);
	proection_key(key, map);
	proection_2d_key(key, map);
	color_key(key, map);
	if (key == 3)
	{
		window_key(map);
		return (0);
	}
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
	return (0);
}
