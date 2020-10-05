#include "fillit.h"

void	print_char_elements(t_element *element)
{
	t_element	*tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tmp = element;
	print_null(tmp);
	while (tmp != NULL)
	{
		while (i < tmp->rows)
		{
			while (j < tmp->rows)
			{
				write(1, &tmp->matrix[i][j] + 48, 1);
				j++;
			}
			write(1, "\n", 1);
			j = 0;
			i++;
		}
		write(1, "\n", 1);
		i = 0;
		tmp = tmp->next;
	}
}

void	print_elements(t_element *element)
{
	t_element	*tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tmp = element;
	print_null(tmp);
	while (tmp != NULL)
	{
		while (i < tmp->rows)
		{
			while (j < tmp->rows)
			{
				write(1, &tmp->matrix[i][j], 1);
				j++;
			}
			write(1, "\n", 1);
			j = 0;
			i++;
		}
		write(1, "\n", 1);
		i = 0;
		tmp = tmp->next;
	}
}

void	print_solution(t_solution *solution)
{
	t_solution	*tmp;
	int			i;
	int			j;

	i = 3;
	j = 3;
	tmp = solution;
	if (tmp == NULL)
		ft_putstr("null");
	while (i < tmp->size + SOLUTION_BUF - 3)
	{
		while (j < tmp->size + SOLUTION_BUF - 3)
		{
			write(1, &tmp->map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 3;
		i++;
	}
	i = 0;
}

void	print_solution_char(t_solution *solution)
{
	t_solution	*tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tmp = solution;
	if (tmp == NULL)
		ft_putstr("null");
	while (i < tmp->size + SOLUTION_BUF)
	{
		while (j < tmp->size + SOLUTION_BUF)
		{
			write(1, &tmp->map[i][j] + 48, 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
	write(1, "\n", 1);
	i = 0;
}

void	print_null(t_element *tmp)
{
	if (tmp == NULL)
		ft_putstr("null");
}
