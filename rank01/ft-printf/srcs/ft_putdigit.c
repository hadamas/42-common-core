/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <ahadama-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:12:41 by ahadama-          #+#    #+#             */
/*   Updated: 2023/11/17 18:46:51 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_print.h"

static	int	convert_hex(unsigned long long n, char *symbols)
{
	char    *nbr[16];
	int	count;

	count = 0;
	if (n == 0)
		return (ft_putchar('0'));
	

}
int	ft_puthex(unsigned long n, int base)
{
	char	*symbols_lo;
	char	*symbols_up;
	int	result;

	symbols_lo = "0123456789abcdef";
	symbols_up = "0123456789ABCDEF";
	
}
