/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:44:03 by ahadama-          #+#    #+#             */
/*   Updated: 2024/03/26 17:47:57 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	count_words(char *str, char separator)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator && *str)
			str++;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				count++;
				inside_word = true;
			}
			str++;
		}
	}
	return (count);
}

static char	*ft_next_word(char *str, char separator)
{
	static int	i;
	int			j;
	int			len;
	char		*next_word;

	i = 0;
	j = 0;
	len = 0;
	while (str[i] == separator && *str)
		i++;
	while ((str[i + len] != separator) && str[i + len])
		len++;
	next_word = malloc(sizeof(char) * (size_t)len + 1);
	if (!next_word)
		return (NULL);
	while (str[i] != separator && str[i])
		next_word[j++] = str[i++];
	next_word[j] = '\0';
	return (next_word);
}

char	**split(char *array, char separator)
{
	int		words_count;
	char	**result_array;
	int		i;

	i = 0;
	words_count = count_words(array, separator);
	if (!words_count)
	{
		exit(1);
	}
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!result_array)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			result_array[i] = malloc(sizeof(char));
			if (!result_array[i])
				return (NULL);
			result_array[i++][0] = '\0';
			continue ;
		}
		result_array[i++] = ft_next_word(array, separator);
	}
	result_array[i] = '\0';
	return (result_array);
}
