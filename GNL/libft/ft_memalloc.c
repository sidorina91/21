#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	mem = NULL;
	if (size)
		mem = malloc(size);
	if (mem)
	{
		ft_bzero(mem, size);
		return (mem);
	}
	return (NULL);
}
