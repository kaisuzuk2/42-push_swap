/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:57:53 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/08 18:20:39 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*make_stack(void)
{
	t_stack	*new_stk;
	t_node	*dummy_node;

	new_stk = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stk)
		return (NULL);
	dummy_node = (t_node *)malloc(sizeof(t_node));
	if (!dummy_node)
		return (free(new_stk), NULL);
	dummy_node->rank = DUMMY_RANK;
	dummy_node->prev = dummy_node;
	dummy_node->next = dummy_node;
	new_stk->size = 0;
	new_stk->dummy_node = dummy_node;
	return (new_stk);
}

void	free_stack(t_stack *stk_a)
{
	t_node	*dummy_node;
	t_node	*cur;
	t_node	*tmp;

	dummy_node = stk_a->dummy_node;
	cur = dummy_node->next;
	while (cur != dummy_node)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	free(stk_a);
}

static t_node	*push_add_back(t_stack *stk_a, int rank)
{
	t_node	*tail;
	t_node	*new;
	t_node	*dummy_node;

	dummy_node = stk_a->dummy_node;
	tail = dummy_node->prev;
	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->rank = rank;
	tail->next = new;
	new->prev = tail;
	new->next = dummy_node;
	dummy_node->prev = new;
	stk_a->size++;
	return (new);
}

t_stack	*stack_utils(int *cmp_arr, int size)
{
	t_stack	*stk_a;
	int		i;

	stk_a = make_stack();
	if (!stk_a)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!push_add_back(stk_a, cmp_arr[i]))
			return (free_stack(stk_a), NULL);
		i++;
	}
	return (stk_a);
}
