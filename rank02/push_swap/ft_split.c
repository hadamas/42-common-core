/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:44:03 by ahadama-          #+#    #+#             */
/*   Updated: 2024/02/29 13:44:07 by ahadama-         ###   ########.fr       */
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
    
}