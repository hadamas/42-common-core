
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*r;

	r = s;
	i = 0;
	while (i < n)
	{
		r[i] = 0;
		i++;
	}
}
