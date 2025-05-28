#include "push_swap.h"

int	get_total_cost(t_cost *cst)
{
	return (cst->ra + cst->rra + cst->rb + cst->rrb + cst->rr + cst->rrr);
}

int	get_forward_cost(t_cost *cst)
{
	return (cst->ra + cst->rb + cst->rr);
}

int	get_backward_cost(t_cost *cst)
{
	return (cst->rra + cst->rrb + cst->rrr);
}

t_cost	*cost_init(t_cost *cst)
{
	cst->ra = 0;
	cst->rra = 0;
	cst->rb = 0;
	cst->rrb = 0;
	cst->rr = 0;
	cst->rrr = 0;
	cst->idx_a = 0;
	return (cst);
}

t_cost	*optimize_common_rotation(t_cost *cst)
{
	while (cst->ra > 0 && cst->rb > 0)
	{
		cst->rr++;
		cst->ra--;
		cst->rb--;
	}
	while (cst->rra > 0 && cst->rrb > 0)
	{
		cst->rrr++;
		cst->rra--;
		cst->rrb--;
	}
	if (get_forward_cost(cst) <= get_backward_cost(cst))
	{
		cst->rrr = 0;
		cst->rra = 0;
		cst->rrb = 0;
	}
	else
	{
		cst->rr = 0;
		cst->ra = 0;
		cst->rb = 0;
	}
	return (cst);
}

t_cost	*stack_b_cost(t_cost *cst, t_stack *stk_b, int rank)
{
	int		i;
	t_stack	*cur;

	i = 0;
	cur = stk_b->next;
	while (cur != stk_b)
	{
		if (cur->rank < rank && rank < cur->next->rank)
			break ;
		cur = cur->next;
		i++;
	}
	cst->rb = i;
	cst->rrb = stk_b->size - i;
	return (cst);
}

t_cost	*calc_cost(t_stack *stk_a, t_stack *stk_b)
{
	t_cost *best_cst;
	t_cost *cur_cst;
	t_stack *cur;
	int idx;

	best_cst = NULL;
	cur = stk_a->next;
	idx = 0;
	while (cur != stk_a)
	{
		cur_cst = (t_cost *)malloc(sizeof(t_cost));
		cost_init(cur_cst);
		cur_cst->ra = idx;
		cur_cst->rra = stk_a->size - idx;
		stack_b_cost(cur_cst, stk_b, cur->rank);
		optimize_common_rotation(cur_cst);
		if (!best_cst || get_total_cost(cur_cst) < get_total_cost(best_cst))
		{
			if (best_cst)
				free(best_cst);
			best_cst = cur_cst;
		}
		else
			free(cur_cst);
		cur = cur->next;
		idx++;
	}
	return (best_cst);
}