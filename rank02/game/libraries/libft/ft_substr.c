
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_src;
	char	*destiny;

	if (!s)
		return (NULL);
	i = 0;
	len_src = ft_strlen(s);
	if (start > len_src)
		return (ft_strdup(""));
	else if (start + len > len_src)
		len = len_src - start;
	destiny = ft_calloc(len + 1, sizeof(char));
	if ((!destiny))
		return (NULL);
	while (s[start] && i < len)
	{
		destiny[i] = s[start];
		i++;
		start++;
	}
	destiny[i] = '\0';
	return (destiny);
}
