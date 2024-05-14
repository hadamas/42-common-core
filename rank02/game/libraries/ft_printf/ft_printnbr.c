/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <ahadama-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:10:20 by ahadama-          #+#    #+#             */
/*   Updated: 2023/11/22 18:24:30 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_nbr(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_printchar('-');
		ft_printchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_printchar('-');
		ft_putnbr(-nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_printchar((nb % 10) + 48);
	}
	else
		ft_printchar(nb + 48);
}

int	ft_printnbr(int nb)
{
	int		len_print;

	if (nb == 0)
	{
		len_print = ft_printchar(48);
		return (len_print);
	}
	ft_putnbr(nb);
	len_print = ft_count_nbr(nb);
	return (len_print);
}
