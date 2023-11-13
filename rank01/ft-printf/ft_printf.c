/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <ahadama-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:14:16 by ahadama-          #+#    #+#             */
/*   Updated: 2023/11/13 19:18:56 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *s)
{
	int	count;

	count = 0;
	while (*s)
		count += write(1, s++, 1);
	return (count);
}

int	ft_print_digit(long n, int base)
{
	int	count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_print_digit(-n, base) + 1)
	}
	else if (n < base)
		return (ft_print_char(symbols[n]));
	else
	{
		count = ft_print_digit(n / base, base);
		return (count + ft_print_digit(n % base, base));
	}
}

int	ft_print_format(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_print_char(va_arg(ap, int));
	else if (c == 's')
		count = ft_print_str(va_arg(ap, char *));
	else if (c == 'p')
		count = ft_print
	else if (c == 'd' || c == 'i')
		count = ft_print_digit((long)va_arg(ap, int), 10);
	else if (c == 'u')
		count = ;
	else if (c == 'x' || c == 'X')
		count = ft_print_digit((long)va_arg(ap, unsigned int), 16);
	else if (c = '%')
		count = 
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *, ...)
{
	va_list ap;
	int	count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += ft_print_format(*++format, ap);
		else
			count += write(STDOUT_FILENO, format, 1);
		++format;
	}
	va_end(ap);
	return count;
}
