/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:08:09 by ahadama-          #+#    #+#             */
/*   Updated: 2023/11/05 16:04:00 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;

	result = malloc(ft_strlen(s) + 1);
	if (!(result))
		return (0);
	ft_memcpy(result, s, ft_strlen(s) + 1);
	return (result);
}
