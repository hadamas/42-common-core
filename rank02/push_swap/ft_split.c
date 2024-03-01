/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:44:03 by ahadama-          #+#    #+#             */
/*   Updated: 2024/03/01 15:12:47 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int count_words(char *str, char separator)
{
    int count;
    bool inside_word;
    
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
                inside_word = true;
                count++;
            }
            str++;
        }
    }
    return (count);
}

static char *ft_nextword(char *str, char separator)
{
    int i;
    int j;
    int len;
    char *nextword;
    
    i = 0;
    j = 0;
    len = 0;
    while (str[i] == separator && *str)
        i++;
    while (str[i + len] != separator && str[i + len])
        len++;
    nextword = malloc(sizeof(char) * (size_t)len + 1);
    if (!nextword)
        return (NULL);
    while (str[i] != separator && str[i])
        nextword[j++] = str[i++];
    nextword[j] = "\0";
    return (nextword);
}

char **ft_split(char *arr, char separator)
{
	int	n_words;
	char  **str_vector;
	int	i;

	i = 0;
	n_words = count_words(*arr, separator);
	str_vector = malloc(sizeof(char *) * (n_words + 2));
	if (!str_vector)
		return (NULL);
	while (n_words-- >= 0)
	{
		if (i == 0)
		{
			str_vector[i] = malloc(sizeof(char));
			if (!str_vector[i])
				return (NULL);
			str_vector[i++][0] = '\0';
			continue;
		}
		str_vector[i++] = ft_nextword(str, separator);
	}
	str_vector[i] = '\0';
	return (str_vector);
}
