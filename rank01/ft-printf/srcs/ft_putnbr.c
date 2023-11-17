/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <ahadama-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:10:20 by ahadama-          #+#    #+#             */
/*   Updated: 2023/11/17 15:19:56 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putstr("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		sign = ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr((n / 10));
	count += ft_putchar ((n % 10) + 48);
	return (count + sign);
}
