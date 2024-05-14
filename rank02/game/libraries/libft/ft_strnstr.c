
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lenl;

	if (little[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	j = 0;
	lenl = ft_strlen(little);
	while (big[i] && i < len)
	{
		while (big[i + j] == little
			[j] && i + j < len && big[i + j] != '\0')
			j++;
		if (j == lenl)
			return ((char *)(big + i));
		j = 0;
		i++;
	}
	return (NULL);
}
