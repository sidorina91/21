#include "fdf.h"

void	free_map(t_map *map)
{
	if (map == NULL)
		return ;
	free_map_matrix(map);
	free_map_file(map);
	ft_memdel((void**)&map);
	return ;
}

void	free_map_matrix(t_map *map)
{
	int i;

	i = 0;
	if (map->matrix == NULL)
		return ;
	while (i < map->rows)
	{
		ft_memdel((void**)&(map->matrix[i]));
		i++;
	}
	ft_memdel((void**)&(map->matrix));
	return ;
}

void	free_map_file(t_map *map)
{
	int i;

	i = 0;
	if (map->file == NULL)
		return ;
	while (i < map->rows)
	{
		ft_memdel((void**)&(map->file[i]));
		i++;
	}
	ft_memdel((void**)&(map->file));
	return ;
}
