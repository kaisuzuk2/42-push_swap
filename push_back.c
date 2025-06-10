/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:07:04 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/08 21:38:03 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_a_rotate(t_stack *stk_a)
{
	int		max;
	int		mid;
	t_node	*tail;

	tail = get_max_node(stk_a);
	max = get_max_node_index(stk_a);
	mid = stk_a->size / 2;
	if (max <= mid)
		while (stk_a->dummy_node->prev != tail)
			rotate_a(stk_a);
	else
		while (stk_a->dummy_node->prev != tail)
			reverse_rotate_a(stk_a);
}

static void	push_back_check(t_stack *stk_a, t_stack *stk_b)
{
	t_node	*stk_a_tail;
	t_node	*stk_b_top;
	t_node	*stk_a_top;

	stk_a_tail = stk_a->dummy_node->prev;
	stk_b_top = stk_b->dummy_node->next;
	stk_a_top = stk_a->dummy_node->next;
	if (stk_b_top == stk_b->dummy_node)
		return ;
	stk_a_tail = stk_a->dummy_node->prev;
	stk_a_top = stk_a->dummy_node->next;
	while (stk_a_top->rank - 1 == stk_a_tail->rank)
	{
		reverse_rotate_a(stk_a);
		stk_a_tail = stk_a->dummy_node->prev;
		stk_a_top = stk_a->dummy_node->next;
	}
	stk_b_top = stk_b->dummy_node->next;
	stk_a_tail = stk_a->dummy_node->prev;
	while (stk_b_top->rank + 1 == stk_a_tail->rank)
	{
		reverse_rotate_a(stk_a);
		stk_b_top = stk_b->dummy_node->next;
		stk_a_tail = stk_a->dummy_node->prev;
	}
}

void	push_back(t_stack *stk_a, t_stack *stk_b)
{
	int		node_size;
	t_node	*stk_a_tail;

	node_size = stk_a->size + stk_b->size;
	stk_a_tail = stk_a->dummy_node->prev;
	if (stk_a->dummy_node->next->rank < stk_b->dummy_node->next->rank)
	{
		while (stk_a_tail->rank > stk_b->dummy_node->next->rank)
		{
			reverse_rotate_a(stk_a);
			stk_a_tail = stk_a->dummy_node->prev;
		}
	}
	while (stk_b->size)
	{
		push_back_check(stk_a, stk_b);
		if (stk_a->dummy_node->prev->rank == stk_a->size + stk_b->size
			&& stk_a->dummy_node->next->rank == MIN_RANK)
		{
			reverse_rotate_a(stk_a);
			push_back_check(stk_a, stk_b);
		}
		push_a(stk_a, stk_b);
	}
	stack_a_rotate(stk_a);
}
