/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:53:16 by ahadama-          #+#    #+#             */
/*   Updated: 2023/11/03 16:47:47 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_size(int n)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (n < 0)
		sign = 1;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i + sign);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*r;
	int		i;
	int		assist;

	assist = n;
	i = count_size(n);
	r = malloc(sizeof(char) * (i + 1));
	if (!r)
		return (NULL);
	i--;
	while (i >= 0)
	{
		if (i == 0 && n < 0)
			r[i] = '-';
		else
		{
			r[i] = ft_abs(assist % 10) + 48;
			assist = assist / 10;
		}
		i--;
	}
	r[count_size(n)] = '\0';
	return (r);
}
