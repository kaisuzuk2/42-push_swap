#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_stack	*top;
	t_stack	*tail;
	t_stack	*new_tail;

	top = stack->next;
	tail = stack->prev;
	new_tail = tail->prev;
	top->prev = tail;
	tail->next = top;
	tail->prev = stack;
	stack->next = tail;
	new_tail->next = stack;
	stack->prev = new_tail;
}
