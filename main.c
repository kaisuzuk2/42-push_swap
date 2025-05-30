#include "push_swap.h"

#include <stdio.h>

int main(int argc, char **argv)
{
	int i;
	int *arr;
	int *rank;
	t_stack *a_stack;
	t_stack *b_stack;
	t_stack *top;
	t_cost *cst;

	arr = malloc(sizeof(int) * (argc - 1));
	i = 1;
	while (i < argc)
	{
		arr[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	rank = make_rank_array(arr, argc - 1);
	a_stack = stack_utils(rank, argc - 1);
	b_stack = (t_stack *)malloc(sizeof(t_stack));
	b_stack->size = 0;
	b_stack->next = b_stack;
	b_stack->prev = b_stack;
	i = 0;
	while (i < a_stack->size)
	{
		cst = calc_cost(a_stack, b_stack);
		do_sort(cst, a_stack, b_stack);
		i++;
	}
	top = b_stack->next;
	while (top != b_stack)
	{
		printf("%d ", top->rank);
		top = top->next;
	}


}