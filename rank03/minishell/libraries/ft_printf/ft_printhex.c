/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <ahadama-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:12:41 by ahadama-          #+#    #+#             */
/*   Updated: 2023/11/27 11:57:09 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_counthex(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static void	ft_puthex(unsigned int n, const char c)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, c);
		ft_puthex(n % 16, c);
	}
	else
	{
		if (n <= 9)
			ft_printchar(n + 48);
		else
		{
			if (c == 'x')
				ft_printchar(n - 10 + 'a');
			if (c == 'X')
				ft_printchar(n - 10 + 'A');
		}
	}
}

int	ft_printhex(unsigned int n, const char c)
{
	int	len_print;

	len_print = 0;
	if (n == 0)
	{
		len_print += ft_printchar(48);
		return (len_print);
	}
	len_print += ft_counthex(n);
	ft_puthex(n, c);
	return (len_print);
}
