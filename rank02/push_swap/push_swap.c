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
	t_stack_node *a; //store a pointer to stack a
	t_stack_node *b;
 
	a = NULL; //set to avoid undefined behavior
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0])) //checks if the input is incorrect
		return (1);
	else if (ac == 2) //also checks the input
		av = split(av[1], ' '); //call the split and extract each substring
	init_stack_a(&a, av + 1, ac == 2); //initiate stack a and also handle errors
	if (!stack_sorted(a)) //checks if the stack is sorted
	{
		if (stack_len(a) == 2) //if not and there's just 2 nums, swap the them
			sa(&a);
		else if (stack_len(a) == 3) //if not and there's 3 , call the sort three algorithm
			sort_three(&a);
		else //if not and there's more then 3 call sort stacks()
			sort_stacks(&a, &b); 
	}
	free_stack(&a);
	return (0);
}
