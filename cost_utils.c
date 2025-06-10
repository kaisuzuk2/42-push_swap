/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:09:07 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/10 18:36:52 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cost			*calc_optimization_helper(t_cost *cst);

static void	cost_init(t_cost *cst)
{
	cst->rr = 0;
	cst->rrr = 0;
	cst->ra = 0;
	cst->rb = 0;
	cst->rra = 0;
	cst->rrb = 0;
	cst->total_cst = 0;
}

static void	calc_b_cost(t_cost *cst, t_stack *stk_b, int rank)
{
	t_node	*cur;
	int		i;

	if (rank > get_max_node(stk_b)->rank || rank < get_min_node(stk_b)->rank)
	{
		if (rank > get_max_node(stk_b)->rank)
			i = get_max_node_index(stk_b);
		else
			i = get_min_node_index(stk_b) + 1;
		cst->rb = i;
		cst->rrb = (stk_b->size - i) % stk_b->size;
		return ;
	}
	cur = stk_b->dummy_node->next;
	i = 1;
	while (cur != stk_b->dummy_node)
	{
		if (cur->rank > rank && cur->next->rank < rank)
			break ;
		i++;
		cur = cur->next;
	}
	cst->rb = i % stk_b->size;
	cst->rrb = (stk_b->size - i) % stk_b->size;
}

static void	calc_optimization(t_cost *cst)
{
	calc_optimization_helper(cst);
	while (cst->ra && cst->rb)
	{
		cst->ra--;
		cst->rb--;
		cst->rr++;
	}
	while (cst->rra && cst->rrb)
	{
		cst->rra--;
		cst->rrb--;
		cst->rrr++;
	}
	cst->total_cst = cst->rr + cst->rrr + cst->ra + cst->rb + cst->rra
		+ cst->rrb;
}

static t_cost	*total_cost_set(t_stack *stk_a, t_stack *stk_b, int rank, int i)
{
	t_cost	*cst;

	cst = (t_cost *)malloc(sizeof(t_cost));
	if (!cst)
		return (NULL);
	cost_init(cst);
	calc_b_cost(cst, stk_b, rank);
	cst->ra = i;
	cst->rra = (stk_a->size - i) % stk_a->size;
	calc_optimization(cst);
	return (cst);
}

t_cost	*calc_cost(t_stack *stk_a, t_stack *stk_b)
{
	t_cost	*best_cst;
	t_cost	*cur_cst;
	t_node	*cur_node;
	int		i;

	best_cst = NULL;
	i = 0;
	cur_node = stk_a->dummy_node->next;
	while (cur_node != stk_a->dummy_node)
	{
		cur_cst = total_cost_set(stk_a, stk_b, cur_node->rank, i);
		if (!cur_cst)
			return (NULL);
		if (!best_cst || cur_cst->total_cst < best_cst->total_cst)
		{
			if (best_cst)
				free(best_cst);
			best_cst = cur_cst;
		}
		else
			free(cur_cst);
		i++;
		cur_node = cur_node->next;
	}
	return (best_cst);
}
