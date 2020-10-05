#include "fillit.h"

int		get_min_solution_size(t_element *element)
{
	int			sqrt;
	int			nbr;
	t_element	*temp;

	temp = element;
	nbr = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		nbr++;
	}
	nbr = 4 * nbr;
	sqrt = 1;
	while (sqrt * sqrt < nbr)
		sqrt++;
	return (sqrt);
}

char	**create_solution_map(int solution_size)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = (char**)ft_memalloc(sizeof(char*) * (solution_size + SOLUTION_BUF));
	while (i < SOLUTION_BUF + solution_size)
	{
		map[i] = (char*)ft_memalloc(sizeof(char) *
			(solution_size + SOLUTION_BUF));
		while (j < SOLUTION_BUF + solution_size)
		{
			map[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}

char	**create_char_solution_map(int solution_size)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = (char**)ft_memalloc(sizeof(char*) * (solution_size + SOLUTION_BUF));
	while (i < SOLUTION_BUF + solution_size)
	{
		map[i] = (char*)ft_memalloc(sizeof(char) *
			(solution_size + SOLUTION_BUF));
		while (j < SOLUTION_BUF + solution_size)
		{
			map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}

void	free_solution(t_solution *solution)
{
	int		i;

	i = 0;
	while (i < solution->size + SOLUTION_BUF)
	{
		ft_memdel((void**)(&(solution->map[i])));
		i++;
	}
	ft_memdel((void**)(&(solution->map)));
	ft_memdel((void**)((&solution)));
}

void	recovery_solution(t_solution *temp_solution,
		t_solution *solution, int fl)
{
	int	i;
	int	j;

	if (fl == 1)
	{
		i = 0;
		j = 0;
		while (i < SOLUTION_BUF + solution->size)
		{
			while (j < SOLUTION_BUF + solution->size)
			{
				temp_solution->map[i][j] = solution->map[i][j];
				j++;
			}
			j = 0;
			i++;
		}
	}
	return ;
}
