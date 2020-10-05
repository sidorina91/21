#include "fdf.h"

void	error(t_map *map)
{
	free_map(map);
	ft_putstr("error args\n");
	exit(0);
}

int		main(int argc, char **argv)
{
	t_map	*map;

	map = NULL;
	if (argc != 2)
		error(map);
	map = read_map(argv[1]);
	convert_map(map);
	map_create(map);
	draw(map);
	mlx_hook(map->win_ptr, 2, 0, deal_key, map);
	mlx_loop(map->mlx_ptr);
	free_map(map);
}
