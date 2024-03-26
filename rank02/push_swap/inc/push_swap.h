/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadama- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:16:45 by ahadama-          #+#    #+#             */
/*   Updated: 2024/03/26 18:57:20 by ahadama-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft/libft.h"

#ifndef	true
#define	true 1
#endif

#ifndef false
#define false 0
#endif

typedef unsigned char bool;

#define INT_MIN -2147483647
#define INT_MAX 2147483647
#define LONG_MAX 2147483647
#define LONG_MIN -2147483647

typedef struct s_stack_node
{
	int	nbr;
	int	index;
	int	push_cost;
	bool	above_median;
	bool	cheapest;

	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//Handle Errors
int		error_syntax(char *str_n);
int		error_duplicate(t_stack_node *a, int n);
void	free_stack(t_stack_node **stack);
void	free_errors(t_stack_node **a);


//Stack Initiation
void    init_stack_a(t_stack_node **a, char **av);
char	**split(char *array, char separator);

//Nodes Initiation
void 	init_nodes_a(t_stack_node  *a, t_stack_node *b);
void	init_nodes_b(t_stack_node *a, t_stack_node *b);
void 	current_index(t_stack_node *stack);
void 	set_cheapest(t_stack_node *stack);
t_stack_node *get_cheapest(t_stack_node *stack);
void    prep_for_push(t_stack_node  **stack, t_stack_node *top_node, char stack_name);

//Stack Utils
int stack_len(t_stack_node *stack);
t_stack_node    *find_last(t_stack_node *stack);
bool    stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

//Commands
void	pa(t_stack_node **a, t_stack_node **b, bool print);
void	pb(t_stack_node **b, t_stack_node **a, bool print);
void	rra(t_stack_node **a, bool print);
void	rrb(t_stack_node **b, bool print);
void	rrr(t_stack_node **a, t_stack_node **b, bool print);
void	ra(t_stack_node **a, bool print);
void	rb(t_stack_node **b, bool print);
void	rr(t_stack_node **a, t_stack_node **b, bool print);
void	sa(t_stack_node	**a, bool print);
void	sb(t_stack_node **b, bool print);
void	ss(t_stack_node **a, t_stack_node **b, bool print);

//Algorithms
void    sort_three(t_stack_node **a);
void    sort_stacks(t_stack_node **a, t_stack_node **b);

#endif
