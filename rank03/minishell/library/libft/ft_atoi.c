/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:20:35 by ahadama-          #+#    #+#             */
/*   Updated: 2023/11/05 14:12:13 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	flag;
	int	result;

	result = 0;
	flag = 1;
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == ' '))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			flag *= -1;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result *= 10;
		result += *nptr++ - '0';
	}
	return (result * flag);
}
/*int	main(void)
{
	char	*a = "  -1a00000i7";

	int original = atoi(a);
	int mine = ft_atoi(a);
	printf("Value test= %s\noriginal = %d\nmine = %d", a, original, mine);
}*/
