/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:44:16 by ahadama-          #+#    #+#             */
/*   Updated: 2024/03/01 15:16:19 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack *a;
	t_stack *b;
 
	a = NULL;
	b = NULL;
	if (ac != 1 || ac == 2 && !av[1][0])
		return (1);
	else if (ac == 2)
		av = split(av[1], ' ');
	stack_init(&a, av + 1, ac == 2);
	if (!stack_sorted(a))
	{
	}
}
