/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:56:21 by ahadama-          #+#    #+#             */
/*   Updated: 2024/05/15 14:56:24 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len_s;

	len_s = ft_strlen(s);
	if (!s)
		return (NULL);
	while (len_s >= 0)
	{
		if (s[len_s] == c)
			return ((char *)(s + len_s));
		len_s--;
	}
	return (NULL);
}
