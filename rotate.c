#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_stack	*top;
	t_stack	*tail;
	t_stack	*new_top;

	top = stack->next;
	tail = stack->prev;
	new_top = top->next;
	new_top->prev = stack;
	tail->next = top;
	top->prev = tail;
	top->next = stack;
	stack->prev = top;
	stack->next = new_top;
}
