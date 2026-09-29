
#include "libft.h"

static int	amontw(char const *s, char c)
{
	size_t	i;
	size_t	amont;

	i = 0;
	amont = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			amont++;
		i++;
	}
	return (amont + 1);
}

static char	**ft_mallsplit(char const *s, char **r, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			len++;
		if (s[i] == c || s[i + 1] == '\0')
		{
			r[j] = malloc(sizeof(char) * (len + 1));
			if (!r[j])
				return (NULL);
			j++;
			len = 0;
			while (s[i + 1] == c && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
	r[j] = 0;
	return (r);
}

static void	ft_fillsplit(char const *s, char **r, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			r[j][k] = s[i];
			k++;
		}
		if (s[i] == c || s[i + 1] == '\0')
		{
			r[j][k] = '\0';
			k = 0;
			j++;
			while (s[i + 1] == c && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
}

static void	ft_freesplit(char *aux, char c, char **r)
{
	int	i;

	i = 0;
	while (i < amontw(aux, c))
	{
		free(r[i]);
		i++;
	}
	free(aux);
	free(r);
}

char	**ft_split(char const *s, char c)
{
	char	**r;
	char	set[2];
	char	*aux;

	if (!s)
		return (NULL);
	set[0] = c;
	set[1] = '\0';
	aux = ft_strtrim(s, set);
	if (!aux)
		return (NULL);
	r = malloc(sizeof(char *) * (amontw(aux, c) + 1));
	if (!r)
	{
		free(aux);
		return (NULL);
	}
	if (!ft_mallsplit(aux, r, c))
	{
		ft_freesplit(aux, c, r);
		return (NULL);
	}
	ft_fillsplit(aux, r, c);
	free(aux);
	return (r);
}
