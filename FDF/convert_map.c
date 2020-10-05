#include "fdf.h"

void	check_space(t_map *map, int space, int tmp_space)
{
	if (tmp_space != space)
	{
		free_map(map);
		ft_putstr("error!");
		exit(0);
	}
}

int		check_i_j(t_map *map, int i, int j)
{
	if (map->file[i][j] == ' '
			&& map->file[i][j + 1] != ' '
			&& map->file[i][j + 1] != 0
			&& map->file[i][j] != 0
			&& j != 0)
		return (1);
	return (0);
}

void	write_map_col(t_map *map)
{
	int j;
	int i;
	int space;
	int tmp_space;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		if (map->file[i][j])
			space = 1;
		while (map->file[i][j])
		{
			space = space + check_i_j(map, i, j);
			j++;
		}
		if (i == 0)
			tmp_space = space;
		check_space(map, space, tmp_space);
		i++;
	}
	map->cols = space;
	return ;
}

void	convert_map(t_map *map)
{
	int		i;
	int		j;
	char	**mas_str;

	write_map_col(map);
	create_map_matrix(map);
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		mas_str = ft_strsplit(map->file[i], ' ');
		while (j < map->cols)
		{
			map->matrix[i][j] = ft_atoi(mas_str[j]);
			ft_memdel((void**)&(mas_str[j]));
			j++;
		}
		ft_memdel((void**)&mas_str);
		i++;
	}
	free_map_file(map);
}

void	create_map_matrix(t_map *map)
{
	int i;

	map->matrix = (int**)ft_memalloc(sizeof(int**) * map->rows);
	i = 0;
	while (i < map->rows)
	{
		map->matrix[i] = (int*)ft_memalloc(sizeof(int*) * map->cols);
		i++;
	}
}
