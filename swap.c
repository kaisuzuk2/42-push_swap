#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_stack	*prev_top;
	t_stack	*new_top;

	prev_top = stack->next;
	new_top = stack->next->next;
	stack->next = new_top;
	new_top->prev = stack;
	prev_top->next = new_top->next;
	prev_top->prev = new_top;
	new_top->next->prev = prev_top;
	new_top->next = prev_top;
}
