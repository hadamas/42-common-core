/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <ahadama-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:19:15 by ahadama-          #+#    #+#             */
/*   Updated: 2023/11/24 17:04:28 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_putunsnbr(unsigned int nb)
{
	if (nb > 9)
	{
		ft_putunsnbr(nb / 10);
		ft_printchar((nb % 10) + 48);
	}
	else
		ft_printchar(nb + 48);
}

int	ft_print_unsint(unsigned int n)
{
	int		len_print;

	len_print = 0;
	if (n == 0)
		len_print += ft_printchar(48);
	else
	{
		ft_putunsnbr(n);
		len_print += ft_count(n);
	}
	return (len_print);
}
