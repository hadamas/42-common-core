/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
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

char **split(char *array, char separator)
{
	int	words_count; //number of substrings counted
	char  **result_array; //to store a pointer to pointers, the array with all substrings
	int	i; //to iterate through the array

	i = 0;
	words_count = count_words(array, separator);
    if (!words_count)
        exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2)); //allocate memory for the result_array based on 'words_count' + 2 additional slots for the '\0' at the end of the last string and the '\0' of the entire array
	if (!result_array)
		return (NULL);
	while (words_count-- >= 0) //iterates through the words to be splited
	{
		if (i == 0) //check if the first carc
		{
			result_array[i] = malloc(sizeof(char));
			if (!result_array[i])
				return (NULL);
			result_array[i++][0] = '\0';
			continue;
		}
		result_array[i++] = ft_nextword(array, separator);
	}
	result_array[i] = '\0';
	return (result_array);
}
