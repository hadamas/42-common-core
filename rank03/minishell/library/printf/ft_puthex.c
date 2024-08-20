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

static	int	ft_convert(unsigned long long n, char *symbols)
{
	char	nbr[16];
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (n == 0)
		return (ft_putchar('0'));
	while (n > 0)
	{
		nbr[i] = symbols[n % 16];
		n /= 16;
		i++;
	}
	nbr[i] = '\0';
	count = i;
	while (i--)
		ft_putchar(nbr[i]);
	return (count);
}

int	ft_puthex(unsigned long long n, int c)
{
	char	*symbols_lo;
	char	*symbols_up;
	int		result;

	symbols_lo = "0123456789abcdef";
	symbols_up = "0123456789ABCDEF";
	result = 0;
	if (c == 'x')
		result = ft_convert(n, symbols_lo);
	else if (c == 'X')
		result = ft_convert(n, symbols_up);
	else
	{
		if (n == 0 && (c == 'x' || c == 'X'))
			return (0);
		if (n == 0)
			result = ft_putstr("(nil)");
		else
		{
			result = ft_putstr("0x");
			result += ft_convert(n, symbols_lo);
		}
	}
	return (result);
}
