#include "fdf.h"

void	print_text(t_map *map)
{
	mlx_string_put(map->mlx_ptr, map->win_ptr, 20, 10,
			map->text_color, "bhoth");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 20, 50,
			map->text_color, "Projection : space");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 20, 70,
			map->text_color, "Move : arrows");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 20, 90,
			map->text_color, "Zoom : + - scroll");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 20, 110,
			map->text_color, "Height : < >");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 20, 130,
			map->text_color, "X rotation : q w");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 20, 150,
			map->text_color, "Y rotation : a s");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 20, 170,
			map->text_color, "Z rotation : z x");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 20, 190,
			map->text_color, "Map color : c v");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 20, 210,
			map->text_color, "Text color : b n");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 20, 230,
			map->text_color, "2d proection : u i o p");
}
