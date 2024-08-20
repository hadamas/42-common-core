/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <ahadama-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:44:24 by ahadama-          #+#    #+#             */
/*   Updated: 2023/11/23 14:29:38 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_ptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	while (ptr != 0)
	{
		ptr = ptr / 16;
		i++;
	}
	return (i);
}

static void	ft_putptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_printchar(ptr + 48);
		else
			ft_printchar((ptr - 10) + 'a');
	}
}

int	ft_printptr(unsigned long long ptr)
{
	int	len_print;

	if (ptr == 0)
	{
		len_print = ft_printstr("(nil)");
		return (len_print);
	}
	len_print = 0;
	len_print += write(1, "0x", 2);
	ft_putptr(ptr);
	len_print += ft_count_ptr(ptr);
	return (len_print);
}
