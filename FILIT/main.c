#include "fillit.h"

int		get_tetr_count(t_element *element)
{
	int			nbr;
	t_element	*temp;

	temp = element;
	nbr = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		nbr++;
	}
	return (nbr);
}

void	glob_sol_iteration(t_glob_sol *glob_sol)
{
	glob_sol->j = 0;
	glob_sol->i++;
}

int		main(int argc, char **argv)
{
	t_element		*element;
	t_solution		*global_solution;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	global_solution = NULL;
	element = create_elements(argv[1]);
	if (element == NULL)
	{
		ft_putstr("error\n");
		exit(0);
	}
	if (get_tetr_count(element) > 26 || !check_elements(element))
	{
		free_elements(element);
		ft_putstr("error\n");
		exit(0);
	}
	global_solution = solution(element, global_solution);
	print_solution(global_solution);
	exit(0);
	return (0);
}
