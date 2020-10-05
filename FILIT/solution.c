#include "fillit.h"

t_solution		*create_new_solution_with_copy(t_solution *solution)
{
	t_solution	*temp_solution;
	int			i;

	i = 0;
	temp_solution = (t_solution*)malloc(sizeof(t_solution));
	temp_solution->size = solution->size;
	temp_solution->map = (char**)malloc(sizeof(char*) *
			(solution->size + SOLUTION_BUF));
	while (i < (solution->size + SOLUTION_BUF))
	{
		temp_solution->map[i] = ft_strdup(solution->map[i]);
		i++;
	}
	return (temp_solution);
}

t_solution		*create_char_solution(int solution_size)
{
	t_solution	*solution;

	solution = (t_solution*)malloc(sizeof(t_solution));
	solution->size = solution_size;
	solution->map = create_char_solution_map(solution_size);
	return (solution);
}

t_solution		*create_solution(int solution_size)
{
	t_solution	*solution;

	solution = (t_solution*)malloc(sizeof(t_solution));
	solution->size = solution_size;
	solution->map = create_solution_map(solution_size);
	return (solution);
}

t_solution		*solution(t_element *element, t_solution *global_solution)
{
	t_solution	*solution;
	t_solution	*char_solution;
	int			min_solution_size;

	min_solution_size = get_min_solution_size(element);
	global_solution = create_char_solution(min_solution_size);
	solution = create_solution(min_solution_size);
	char_solution = create_char_solution(min_solution_size);
	while (!(find_sol(solution, element, char_solution, global_solution)))
	{
		min_solution_size = min_solution_size + 1;
		free_solution(solution);
		free_solution(char_solution);
		free_solution(global_solution);
		solution = create_solution(min_solution_size);
		char_solution = create_char_solution(min_solution_size);
		global_solution = create_char_solution(min_solution_size);
	}
	free_solution(solution);
	free_solution(char_solution);
	return (global_solution);
}

t_glob_sol		*global_free_solutions(t_glob_sol *glob_sol)
{
	free_solution(glob_sol->tmp_sol);
	glob_sol->tmp_sol = NULL;
	free_solution(glob_sol->tmp_ch_sol);
	glob_sol->tmp_ch_sol = NULL;
	ft_memdel((void**)(&glob_sol));
	return (NULL);
}
