#include "push_swap.h"

static void do_rotate_both(t_cost *cst, t_stack *stk_a, t_stack *stk_b)
{
	while (cst->rr)
	{
		rotate(stk_a);
		rotate(stk_b);
		cst->rr--;
	}
	while (cst->rrr)
	{
		reverse_rotate(stk_a);
		reverse_rotate(stk_b);
		cst->rrr--;
	}
}

static void do_rotate(t_cost *cst, t_stack *stk_a, t_stack *stk_b)
{
	while (cst->ra)
	{
		rotate(stk_a);
		cst->ra--;
	}
	while (cst->rb)
	{
		rotate(stk_b);
		cst->rb--;
	}
	while (cst->rra)
	{
		reverse_rotate(stk_a);
		cst->rra--;
	}
	while (cst->rrb)
	{
		reverse_rotate(stk_b);
		cst->rrb--;
	}
}

void	do_sort(t_cost *cst, t_stack *stk_a, t_stack *stk_b)
{
	do_rotate_both(cst, stk_a, stk_b);
	do_rotate(cst, stk_a, stk_b);
	push(stk_b, stk_a);
	free(cst);
}