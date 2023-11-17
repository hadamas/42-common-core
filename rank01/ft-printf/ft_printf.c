/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <ahadama-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:14:16 by ahadama-          #+#    #+#             */
/*   Updated: 2023/11/17 18:19:16 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list ap)
{
	if (n == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (n == 's')
		count += ft_putstr(va_arg(ap, const char *));
	else if (n == 'd' || n == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (n == 'u')
		count += ft_put_u(va_arg(ap, unsigned int), 10);
	else if (n == 'x' || n == 'X')
		count += ft_hex(va_arg(ap, unsigned int), 16);
	else if (n == 'p')
		count += ft_puthex(va_arg(ap, unsigned long long), 16);
	else if (n == '%')
		count += ft_putchar(n);
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%' && ft_strchr("cspdiuxX%", *++str))
			count += ft_print_format(*str++, ap);
		else
			count += ft_putchar(*str);
		*str++;
	}
	va_end(ap);
	return (count);
