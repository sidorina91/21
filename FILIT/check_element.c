#include "fillit.h"

int		check_size_tetr(char **matrix, t_element *temp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < temp->rows)
	{
		while (matrix[i][j])
			j++;
		i++;
		if (j != 4)
			return (0);
		j = 0;
	}
	if (i != 4)
		return (0);
	return (1);
}

int		check_char_tetr(char **matrix)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (matrix[i][j] && j < 4)
		{
			if (matrix[i][j] != '#' && matrix[i][j] != '.')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int		check_tetr_form(char **matrix)
{
	int count;
	int i;
	int j;
	int	r;

	i = 0;
	j = 0;
	r = 0;
	count = 0;
	while (i < 4)
	{
		while (matrix[i][j])
		{
			if (matrix[i][j] == '#')
			{
				count = count + count_adj(matrix, i, j);
				r++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	i = count >= 6 && r == 4 ? 1 : 0;
	return (i);
}

int		count_adj(char **matrix, int i, int j)
{
	int count;

	count = 0;
	if (i + 1 < 4)
		count = (matrix[i + 1][j] == '#' ? count + 1 : count);
	if (i - 1 >= 0)
		count = (matrix[i - 1][j] == '#' ? count + 1 : count);
	if (j + 1 < 4)
		count = (matrix[i][j + 1] == '#' ? count + 1 : count);
	if (j - 1 >= 0)
		count = (matrix[i][j - 1] == '#' ? count + 1 : count);
	return (count);
}

void	tetr_char_replace(t_element *element)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (element->matrix[i][j] == '#')
				element->matrix[i][j] = 1;
			if (element->matrix[i][j] == '.')
				element->matrix[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}
