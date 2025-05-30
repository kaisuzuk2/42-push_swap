#include "push_swap.h"

void	push(t_stack *to_stack, t_stack *from_stack)
{
	t_stack *node;
	t_stack *next;
	t_stack *top;

	if (from_stack->next == from_stack)
		return ;
	node = from_stack->next;
	next = node->next;
	top = to_stack->next;

	from_stack->next = next;
	next->prev = from_stack;
	from_stack->size--;
	
	if (top == to_stack)
	{
		node->prev = to_stack;
		node->next = to_stack;
		to_stack->prev = node;
		to_stack->next = node;
	}
	else
	{
		to_stack->next = node;
		node->prev = to_stack;
		node->next = top;
		top->prev = node;
	}
	to_stack->size++;
}
