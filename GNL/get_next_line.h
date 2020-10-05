#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_element
{
	int					fd;
	char				*buf;
	struct s_element	*next;
}					t_element;

int					get_next_line(const int fd, char **line);

#endif
