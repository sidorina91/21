#include "fillit.h"

int		check_char_solution(char **map, int i, int j, int size)
{
	if (map[i][j] > 1)
		return (0);
	if (map[i][j] > 0 &&
			(i < 3 || i > size + SOLUTION_BUF - 4 ||
			j < 3 || j > size + SOLUTION_BUF - 4))
		return (0);
	return (1);
}

int		check_sol(t_solution *solution)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < SOLUTION_BUF + solution->size)
	{
		while (j < SOLUTION_BUF + solution->size)
		{
			if (!check_char_solution(solution->map, i, j, solution->size))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	pst_tetr_in_sol(t_element *element, t_glob_sol *glob_sol)
{
	int a;
	int b;
	int i;
	int j;

	i = glob_sol->i;
	j = glob_sol->j;
	a = 0;
	b = 0;
	while (a < 4)
	{
		while (b < 4)
		{
			glob_sol->tmp_sol->map[a + i][b + j] =
				glob_sol->tmp_sol->map[a + i][b + j] + element->matrix[a][b];
			if (element->matrix[a][b] == 1)
				glob_sol->tmp_ch_sol->map[a + i][b + j] = element->char_s;
			else if (glob_sol->tmp_ch_sol->map[a + i][b + j] == 0)
				glob_sol->tmp_ch_sol->map[a + i][b + j] = '.';
			b++;
		}
		b = 0;
		a++;
	}
}

int		check_elements(t_element *element)
{
	t_element	*temp;
	int			i;

	i = 0;
	temp = element;
	while (temp != NULL)
	{
		if (check_element(temp->matrix, temp))
		{
			temp->char_s = (char)(65 + i);
			temp = temp->next;
			i++;
		}
		else
			return (0);
	}
	return (1);
}
