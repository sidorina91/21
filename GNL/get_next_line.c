#include "get_next_line.h"

int				ft_positionchar(const char *str, char c)
{
	int position;

	if (str)
	{
		position = 0;
		while (str[position] != '\0')
		{
			if (str[position] == c)
				return (position);
			position++;
		}
		return (-1);
	}
	return (-1);
}

t_element		*create(int fd)
{
	t_element *element;

	element = NULL;
	element = (t_element*)malloc(sizeof(t_element));
	if (element)
	{
		element->fd = fd;
		element->buf = NULL;
		element->next = NULL;
	}
	return (element);
}

int				readfile(t_element *element)
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

int				setline(t_element *element, char **line, int position)
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
	static t_element	*begin;
	t_element			*tmp;

	if (fd < 0 || line == NULL)
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
