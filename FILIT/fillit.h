#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 32
# define SIDE_SIZE 4
# define FREE_STR_GNL 0
# define SOLUTION_BUF 6
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct		s_element
{
	char					**matrix;
	char					char_s;
	int						rows;
	struct s_element		*next;
}					t_element;

typedef struct		s_solution
{
	char					**map;
	int						size;
}					t_solution;

typedef struct		s_element_g
{
	int						fd;
	char					*buf;
	struct s_element_g		*next;
}					t_element_g;

typedef struct		s_glob_sol
{
	t_solution				*tmp_sol;
	t_solution				*tmp_ch_sol;
	int						i;
	int						j;
}					t_glob_sol;

int					get_next_line(const int fd, char **line);
void				tetr_char_replace(t_element *element);
int					count_adj(char **matrix, int i, int j);
int					check_tetr_form(char **matrix);
int					check_char_tetr(char **matrix);
int					check_size_tetr(char **matrix, t_element *temp);
int					check_element(char **mas, t_element *temp);
int					check_elements(t_element *element);
t_element			*create_elements(char *str);
void				free_elements(t_element *element);
void				print_elements(t_element *element);
void				create_matrix(t_element *element, char *buf);
int					get_min_solution_size(t_element *element);
t_solution			*create_new_sollution_with_copy(t_solution *solution);
char				**create_solution_map(int solution_size);
char				**create_char_solution_map(int solution_size);
t_solution			*create_solution(int solution_size);
t_solution			*create_char_solution(int solution_size);
t_solution			*solution(t_element *element, t_solution *global_solution);
int					find_sol(t_solution *solution, t_element *element,
t_solution			*char_solution, t_solution *gl_sol);
void				pst_tetr_in_sol(t_element *element, t_glob_sol *glob_sol);
int					check_char_solution(char **map, int i, int j, int size);
int					check_sol(t_solution *solution);
void				recovery_solution(t_solution *temp_solution,
					t_solution *solution, int fl);
void				print_solution(t_solution *solution);
void				print_solution_char(t_solution *solution);
void				free_solution(t_solution *solution);
void				free_element_matrix(char ***matrix, int count);
void				print_char_elements(t_element *element);
void				print_null(t_element *tmp);
void				global_free(t_element *element,
					t_solution *global_solution);
t_glob_sol			*global_free_solutions(t_glob_sol *glob_sol);
int					create_temp_matrix(t_element *temp, int count, char *buf);
t_element			*read_gnl(char *buf, t_element *temp, int *i);
t_glob_sol			*create_gl_sol(t_solution *solution);
void				glob_sol_iteration(t_glob_sol *glob_sol);

#endif
