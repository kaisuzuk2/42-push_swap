/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:28:40 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/10 18:43:50 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_list_sort(t_stack *stk_a)
{
	t_node	*cur;
	t_node	*dummy_node;

	dummy_node = stk_a->dummy_node;
	cur = dummy_node->next;
	while (cur->next != dummy_node)
	{
		if (!(cur->rank + 1 == cur->next->rank))
			return (0);
		cur = cur->next;
	}
	return (1);
}

static void	push_until_three(t_stack *stk_a, t_stack *stk_b)
{
	int	i;
	int	mid;

	i = get_min_node_index(stk_a);
	mid = stk_a->size / 2;
	if (i < mid)
		while (i--)
			rotate_a(stk_a);
	else
	{
		i = stk_a->size - i;
		while (i--)
			reverse_rotate_a(stk_a);
	}
	push_b(stk_b, stk_a);
}

void	sort_five(t_stack *stk_a, t_stack *stk_b)
{
	int	counter;

	counter = stk_a->size - STACK_MIN_SIZE;
	if (counter < 0)
		return ;
	if (ft_is_list_sort(stk_a))
		return ;
	while (stk_a->size > 3)
		push_until_three(stk_a, stk_b);
	sort_three(stk_a);
	while (counter--)
		push_a(stk_a, stk_b);
}
