#include "push_swap.h"

void push(t_stack *to_stack, t_stack *from_stack)
{
	t_stack *node;
	t_stack *prev_top;

	node = from_stack->next;
	node->next->prev = node->prev;
	node->prev->next = node->next;
	prev_top = to_stack->next;
	to_stack->next = node;
	node->prev = to_stack;
	node->next = prev_top;
	prev_top->prev = node;
}
