
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int			i;

	if (!dest && !src)
		return (NULL);
	if (dest <= src)
	{
		i = 0;
		while (i < (int)n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i--;
		}
	}
	return (dest);
}
