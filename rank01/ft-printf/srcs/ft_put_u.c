/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <ahadama-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:44:24 by ahadama-          #+#    #+#             */
/*   Updated: 2023/11/17 15:45:49 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_put_u(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n >= 10)
		count += ft_put_u(n / 10);
	count += ft_putchar((nbr % 10) + 48);
	return (count);
}
