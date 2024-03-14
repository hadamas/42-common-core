
#include "push_swap.h"


void  current_index(t_stack_node *stack)
{
  int i;
  int median;

  i = 0;
  if (!stack)
    return ;
  median = stack_len(stack) / 2;
  while (stack)
  {
    stack->index = i;
    if (i <= mwedian)
      stack->above_median = true;
    else
      stack->above_median = false;
    stack = stack->next;
    i++;
  }
}

static void  set_target_a(t_stack_node *a, t_stack_node *b)
{
  t_stack_node *current_b;
  t_stack_node *target_node;
  long  best_match_index;

  while (a)
  {
    best_match_index = LONG_MIN;
    current_b = b;
    while (current_b)
    {
      if (current_b->nbr < a->nbr && current_b->nbr > best_match_index)
        best_match_index = current_b->nbr;
    }
  }
}

void  init_nodes_a(t_stack_node  *a, t_stack_node *b)
{
  current_index(a);
  current_index(b);
  set_target_a(a, b);
  cost_analysis_a(a, b);
  set_cheapest(a);
}
