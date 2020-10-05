#include "fillit.h"

void		free_elements(t_element *element)
{
	int	i;

	if (element != NULL)
	{
		if (element->next != NULL)
			free_elements(element->next);
		if (element->matrix != NULL)
		{
			i = 0;
			while (i < element->rows)
			{
				ft_memdel((void**)&(element->matrix[i]));
				i++;
			}
			ft_memdel((void**)&(element->matrix));
		}
		ft_memdel((void**)(&element));
	}
}

int			check_element(char **mas, t_element *temp)
{
	if (check_size_tetr(mas, temp)
			&& check_char_tetr(mas)
			&& check_tetr_form(mas))
	{
		tetr_char_replace(temp);
		return (1);
	}
	return (0);
}

void		free_element_matrix(char ***matrix, int count)
{
	int			i;

	i = 0;
	while (i < count)
	{
		ft_memdel((void**)(&(*matrix[i])));
		i++;
	}
	ft_memdel((void**)(&(*matrix)));
}

void		create_matrix(t_element *element, char *buf)
{
	char		**temp;
	int			i;

	temp = (char**)ft_memalloc(sizeof(char*) * (element->rows + 1));
	i = 0;
	while (i < element->rows)
	{
		temp[i] = ft_strdup(element->matrix[i]);
		ft_memdel((void**)(&(element->matrix[i])));
		i++;
	}
	temp[i] = ft_strdup(buf);
	ft_memdel((void**)(&(element->matrix)));
	element->matrix = temp;
	return ;
}
