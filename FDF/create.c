#include "fdf.h"

void	min_max_z(t_map *map)
{
	int i;
	int j;

	i = 0;
	map->z_max = map->matrix[0][0];
	map->z_min = map->z_max;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->matrix[i][j] > map->z_max)
				map->z_max = map->matrix[i][j];
			if (map->matrix[i][j] < map->z_min)
				map->z_min = map->matrix[i][j];
			j++;
		}
		i++;
	}
}

void	map_create(t_map *map)
{
	if (map->width == 0)
		map_first_create(map);
	else
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		map->last_height = map->height;
		if (map->width == 1920)
		{
			map->width = 2560;
			map->height = 1395;
		}
		else
		{
			map->width = 1920;
			map->height = 1080;
		}
		map->mlx_ptr = mlx_init();
		map->win_ptr = mlx_new_window(map->mlx_ptr, map->width,
			map->height, "FDF");
	}
	min_max_z(map);
}

void	map_first_create(t_map *map)
{
	map->width = 1920;
	map->height = 1080;
	map->last_height = map->height;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, map->width, map->height, "FDF");
	map->x0 = 900;
	map->y0 = 500;
	map->angle_x = 0;
	map->angle_y = 0;
	map->angle_z = 0;
	map->isometr_angle = 0.82;
	map->dist = 2;
	map->color = 0xe80c0c;
	map->zoom = 500 / map->cols;
	map->zoom_z = 1;
	map->text_color = 0x00FF77;
	map->proection = 1;
}
