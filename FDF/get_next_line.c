#include "fdf.h"

t_element_gnl	*create(int fd)
{
	t_element_gnl *element;

	element = NULL;
	element = (t_element_gnl*)malloc(sizeof(t_element_gnl));
	if (element)
	{
		element->fd = fd;
		element->buf = NULL;
		element->next = NULL;
	}
	return (element);
}

int				readfile(t_element_gnl *element)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		position;
	int		count;

	position = -1;
	count = 1;
	while (position < 0 && count > 0)
	{
		if (element->buf == NULL)
			element->buf = ft_strnew(0);
		position = ft_positionchar(element->buf, '\n');
		if (position == -1)
		{
			count = read(element->fd, buf, BUFF_SIZE);
			if (count == -1)
				return (-2);
			buf[count] = '\0';
			tmp = element->buf;
			element->buf = ft_strjoin(element->buf, buf);
			ft_strdel(&tmp);
		}
	}
	return (position);
}

int				setline(t_element_gnl *element, char **line, int position)
{
	char *tmp;

	if (position == -2)
		return (-1);
	if (position == -1)
	{
		*line = ft_strdup(element->buf);
		ft_strdel(&(element->buf));
		return (ft_strlen(*line) > 0);
	}
	else
	{
		tmp = element->buf;
		*line = ft_strsub(element->buf, 0, position);
		element->buf = ft_strsub(element->buf, position + 1,
		ft_strlen(element->buf + position + 1));
		ft_strdel(&tmp);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_element_gnl	*begin;
	t_element_gnl			*tmp;

	if (fd < 0 || fd > 10239 || BUFF_SIZE < 1 || BUFF_SIZE > 2147483647)
		return (-1);
	if (begin == NULL)
		begin = create(fd);
	tmp = begin;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (setline(tmp, line, readfile(tmp)));
		if (tmp->next == NULL)
		{
			tmp->next = create(fd);
			return (setline(tmp->next, line, readfile(tmp->next)));
		}
		tmp = tmp->next;
	}
	free(tmp);
	return (-1);
}
