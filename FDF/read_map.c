#include "fdf.h"

void	fd_error(t_map *map)
{
	if (map)
		ft_memdel((void**)&map);
	ft_putstr("map error!");
	exit(0);
}

void	get_rows(int fd[], t_map *map)
{
	int		i;
	char	*buf;

	i = 0;
	while ((fd[1] = get_next_line(fd[0], &buf)) > 0)
	{
		ft_memdel((void**)&buf);
		i++;
	}
	ft_memdel((void**)&buf);
	map->rows = i;
	close(fd[0]);
}

t_map	*read_map(char *file_str)
{
	t_map	*map;
	int		fd[2];
	int		i;
	char	*buf;

	fd[0] = open(file_str, O_RDONLY);
	if (fd[0] < 0)
		fd_error(NULL);
	map = (t_map*)ft_memalloc(sizeof(t_map));
	get_rows(fd, map);
	map->file = (char**)ft_memalloc(sizeof(char*) * (map->rows));
	fd[0] = open(file_str, O_RDONLY);
	i = 0;
	while ((fd[1] = get_next_line(fd[0], &buf)) > 0)
	{
		map->file[i] = ft_strdup(buf);
		ft_memdel((void**)&buf);
		i++;
	}
	ft_memdel((void**)&buf);
	if (fd[1] < 0)
		fd_error(map);
	close(fd[0]);
	return (map);
}
