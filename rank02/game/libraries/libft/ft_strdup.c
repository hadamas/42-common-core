
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*r;
	int		i;

	i = 0;
	r = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!r)
		return (NULL);
	while (s[i] != '\0')
	{
		r[i] = s[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}
