/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <ahadama-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:19:15 by ahadama-          #+#    #+#             */
/*   Updated: 2023/11/22 18:19:57 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(int n, va_list ap)
{
	if (n == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (n == 's')
		count += ft_putstr(va_arg(ap, const char *));
	else if (n == 'd' || n == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (n == 'u')
		count += ft_putunsigned(va_arg(ap, unsigned int), 10);
	else if (n == 'x' || n == 'X')
		count += ft_puthex(va_arg(ap, unsigned int), 16);
	else if (n == 'p')
		count += ft_puthex(va_arg(ap, unsigned long long), 16);
	else if (n == '%')
		count += ft_putchar(n);
	else
		return (-1);
	return (count);
}
