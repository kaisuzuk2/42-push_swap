/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:58:01 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/10 17:23:21 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack *stk_a)
{
	if (stk_a->dummy_node->next->rank > stk_a->dummy_node->next->next->rank)
		swap_a(stk_a);
}

void	sort_three(t_stack *stk_a)
{
	t_node	*top;
	t_node	*mid;
	t_node	*tail;

	top = stk_a->dummy_node->next;
	mid = top->next;
	tail = mid->next;
	if (stk_a->size <= 2)
		return (sort_two(stk_a));
	if (top->rank < mid->rank && mid->rank < tail->rank)
		return ;
	if (top->rank < mid->rank && mid->rank > tail->rank
		&& top->rank < tail->rank)
		(reverse_rotate_a(stk_a), swap_a(stk_a));
	else if (top->rank < mid->rank && mid->rank > tail->rank
		&& top->rank > tail->rank)
		reverse_rotate_a(stk_a);
	else if (top->rank > mid->rank && mid->rank > tail->rank)
		(swap_a(stk_a), reverse_rotate_a(stk_a));
	else if (top->rank > mid->rank && mid->rank < tail->rank
		&& top->rank < tail->rank)
		swap_a(stk_a);
	else
		rotate_a(stk_a);
}
