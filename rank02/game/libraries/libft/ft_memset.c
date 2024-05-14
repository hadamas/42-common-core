
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		i;
	char		*r;

	r = s;
	i = 0;
	while (i < n)
	{
		r[i] = (char)c;
		i++;
	}
	return (s);
}
