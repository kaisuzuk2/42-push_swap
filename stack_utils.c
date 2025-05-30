#include "push_swap.h"

static void free_list(t_stack *stack)
{
	t_stack *p;
	t_stack *tmp;

	p = stack->next;
	while (p != stack)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}
	free(stack);
}

static t_stack *push_stack(t_stack *stack, int num)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->rank = num;
	if (stack->prev == stack)
		stack->prev = new;
	
	new->prev = stack;
	new->next = stack->next;

	stack->next->prev = new;
	stack->next = new;

	stack->size++;
	return (new);
}

t_stack *stack_utils(int *arr, int size)
{
	t_stack *a_stack;
	int i;

	a_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!a_stack)
		return (NULL);
	a_stack->size = 0;
	a_stack->rank = -1;
	a_stack->prev = a_stack;
	a_stack->next = a_stack;
	i = size;
	while (i--)
	{
		if (!push_stack(a_stack, arr[i]))
		{
			free_list(a_stack);
			return (NULL);
		}
	}
	return (a_stack);
}
