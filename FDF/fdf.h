#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 32
# define HEIGHT	1080
# define WIDTH	1920
# define COLOR	0xffffff
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx.h"
# include "minilibx_macos/mlx.h"

typedef struct		s_map
{
	char			**file;
	int				**matrix;
	int				cols;
	int				rows;
	int				max_heigt;
	float			angle_x;
	float			sin_x;
	float			cos_x;
	float			angle_y;
	float			sin_y;
	float			cos_y;
	float			angle_z;
	float			sin_z;
	float			cos_z;
	float			isometr_angle;
	float			zoom;
	float			zoom_z;
	float			dist;
	int				x0;
	int				y0;
	int				color;
	int				text_color;
	void			*mlx_ptr;
	void			*win_ptr;
	int				proection;
	int				width;
	int				height;
	int				last_height;
	int				z_min;
	int				z_max;
	int				proection_2d;
}					t_map;

typedef struct		s_xyz
{
	float			x;
	float			x1;
	float			y;
	float			y1;
	float			z;
	float			z1;
	float			last_x;
	float			z_tmp;
	float			z1_tmp;
	float			step_x;
	float			step_y;
}					t_xyz;

typedef struct		s_element_gnl
{
	int						fd;
	char					*buf;
	struct s_element_gnl	*next;
}					t_element_gnl;

int					get_next_line(const int fd, char **line);
void				map_write(t_map *map, char **buf, int *i_tmp);
void				fd_error(t_map *map);
t_map				*read_map(char *file_str);
void				error(t_map *map);
void				write_map_col(t_map *map);
void				convert_map(t_map *map);
void				free_map(t_map *map);
void				free_map_matrix(t_map *map);
void				free_map_file(t_map *map);
void				create_map_matrix(t_map *map);
void				draw(t_map *map);
float				max(float n1, float n2);
float				min(float n1, float n2);
float				mod(float n);
int					deal_key(int key, t_map *map);
void				map_create(t_map *map);
void				print_text(t_map *map);
void				point_rotation(t_xyz *xyz, t_map *map);
void				motion(t_xyz *xyz, t_map *map);
void				point_zoom(t_xyz *xyz, t_map *map);
void				point_proection(t_xyz *xyz, t_map *map);
void				exit_key(int key, t_map *map);
void				proection_key(int key, t_map *map);
void				rotate_key(int key, t_map *map);
void				point_z_zoom(t_xyz *xyz, t_map *map);
void				map_first_create(t_map *map);
void				print_on_disp(t_map *map);
void				create_disp_matrix(t_map *map);
void				map_first_create(t_map *map);
void				clear_matrix(t_map *map);
int					check_i_j(t_map *map, int i, int j);
void				check_space(t_map *map, int space,
						int tmp_space);
int					get_color(t_xyz *xyz, t_map *map);
void				color_key(int key, t_map *map);
void				bresenham_ready(t_xyz *xyz, t_map *map, int x, int y);
void				init_steps(t_xyz *xyz);
void				init_xyz(t_xyz *xyz, t_map *map);
void				proection_2d_key(int key, t_map *map);
void				point_proection2d(t_xyz *xyz, t_map *map);

#endif
