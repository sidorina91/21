#include "fdf.h"

void	exit_key(int key, t_map *map)
{
	if (key == 53)
	{
		free_map(map);
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(0);
	}
}

void	proection_key(int key, t_map *map)
{
	if (key == 49 && map->proection == 0)
		map->proection = 1;
	else if (key == 49 && map->proection == 1)
		map->proection = 0;
}

void	rotate_key(int key, t_map *map)
{
	if (key == 12)
		map->angle_x += 0.05;
	if (key == 13)
		map->angle_x -= 0.05;
	if (key == 0)
		map->angle_y += 0.05;
	if (key == 1)
		map->angle_y -= 0.05;
	if (key == 6)
		map->angle_z += 0.05;
	if (key == 7)
		map->angle_z -= 0.05;
}

void	color_key(int key, t_map *map)
{
	if (key == 9)
		map->color = map->color + 10;
	if (key == 8)
		map->color = map->color - 10;
	if (key == 45)
		map->text_color = map->text_color + 10;
	if (key == 11)
		map->text_color = map->text_color - 10;
}

void	proection_2d_key(int key, t_map *map)
{
	if (key == 34)
		map->proection_2d = 1;
	if (key == 31)
		map->proection_2d = 2;
	if (key == 35)
		map->proection_2d = 3;
	if (key == 32)
		map->proection_2d = 0;
}