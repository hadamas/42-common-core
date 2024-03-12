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

# include <limits.h>
# include <stdbool.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_print.h"


typedef struct s_stack_node
{
	int	nbr;
	int	index;
	int	push_cost;
	bool	above_median;
	bool	cheapest;

	struct s_stack	*target;
	struct s_tack	*next;
	struct s_stack	*prev;
}	t_stack_node;

//handle input


Handle Errors


//Stack Initiation


//Nodes Initiation


//Stack Utils


//Commands


//Algorithms




#endif
