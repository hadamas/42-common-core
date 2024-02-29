/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:16:45 by ahadama-          #+#    #+#             */
/*   Updated: 2024/02/29 14:33:40 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack
{
	int	value;
	int	c_position;
	int	final_index;
	int	push;
	bool	up_middle;
	bool	cheapest;
	struct s_stack	*target;
	struct s_tack	*next;
	struct s_stack	*prev;
}	t_stack

//handle input


Handle Errors

Stack Creation

Linked List Utils

Algorithms

Commands




#endif
