/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <ahadama-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:12:41 by ahadama-          #+#    #+#             */
/*   Updated: 2023/11/22 17:59:48 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_print.h"

static	int	ft_convert(unsigned long long n, char *symbols)
{
	char    nbr[16];
	int	count;

	count = 0;
	if (n == 0)
		return (ft_putchar('0'));
	while(n > 0)
	{
		*nbr++ = symbols[n % 16];
		n /= 16;
		count++;
	}
	*nbr = '\0';
	while (count--)
		ft_putchar(n);
	return (count);
}
int	ft_puthex(unsigned long n, int base)
{
	char	*symbols_lo;
	char	*symbols_up;
	int	result;

	symbols_lo = "0123456789abcdef";
	symbols_up = "0123456789ABCDEF";
	result = 0;

	if (n == 'x')
		result = ft_convert(n, symbols_lo);
	else if (n == 'X')
		result = ft_convert(n, symbols_up);
	else
	{
		if (n == 0)
			return (0);
		else
		{
			result = ft_putstr("0x");
			result += ft_convert(n, symbols_lo);
		}
	}
	return (result);
}
