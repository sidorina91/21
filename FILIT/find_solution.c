#include "fillit.h"

int			find_sol(t_solution *solution, t_element *element,
				t_solution *char_solution, t_solution *gl_sol)
{
	t_glob_sol	*glob_sol;
	int			fl;

	glob_sol = create_gl_sol(solution);
	fl = (element == NULL ? 1 : 0);
	while (glob_sol->i < solution->size + SOLUTION_BUF - 3 && !(fl))
	{
		while (glob_sol->j < solution->size + SOLUTION_BUF - 3)
		{
			recovery_solution(glob_sol->tmp_sol, solution, 1);
			recovery_solution(glob_sol->tmp_ch_sol, char_solution, 1);
			pst_tetr_in_sol(element, glob_sol);
			if (check_sol(glob_sol->tmp_sol) && find_sol(glob_sol->tmp_sol,
				element->next, glob_sol->tmp_ch_sol, gl_sol))
			{
				glob_sol = global_free_solutions(glob_sol);
				return (1);
			}
			glob_sol->j++;
		}
		glob_sol_iteration(glob_sol);
	}
	recovery_solution(gl_sol, char_solution, fl);
	glob_sol = global_free_solutions(glob_sol);
	return (fl);
}

t_glob_sol	*create_gl_sol(t_solution *solution)
{
	t_glob_sol	*gl_sol;

	gl_sol = (t_glob_sol*)ft_memalloc(sizeof(t_glob_sol));
	gl_sol->i = 0;
	gl_sol->j = 0;
	gl_sol->tmp_sol = create_solution(solution->size);
	gl_sol->tmp_ch_sol = create_char_solution(solution->size);
	return (gl_sol);
}

t_element	*create_elements(char *str)
{
	int			fd_gnl[2];
	int			i;
	char		*buf;
	t_element	*temp;
	t_element	*element;

	fd_gnl[0] = open(str, O_RDONLY);
	if (fd_gnl[0] < 0)
		return (NULL);
	i = 0;
	element = (t_element*)ft_memalloc(sizeof(t_element));
	temp = element;
	while ((fd_gnl[1] = get_next_line(fd_gnl[0], &buf)) > 0)
	{
		temp = read_gnl(buf, temp, &i);
		ft_memdel((void**)&buf);
	}
	if (fd_gnl[1] < 0)
		exit(0);
	ft_memdel((void**)&buf);
	close(fd_gnl[0]);
	return (element);
}

int			create_temp_matrix(t_element *temp, int i, char *buf)
{
	create_matrix(temp, buf);
	temp->next = NULL;
	i++;
	temp->rows = i;
	return (i);
}

t_element	*read_gnl(char *buf, t_element *temp, int *i)
{
	if (*buf == FREE_STR_GNL)
	{
		temp->next = (t_element*)ft_memalloc(sizeof(t_element));
		temp = temp->next;
		*i = 0;
	}
	else
		*i = create_temp_matrix(temp, *i, buf);
	return (temp);
}
