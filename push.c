/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:49:27 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/09 18:03:56 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *to_stack, t_stack *from_stack)
{
	t_node	*node;
	t_node	*top;
	t_node	*from_dummy_node;
	t_node	*to_dummy_node;

	from_dummy_node = from_stack->dummy_node;
	to_dummy_node = to_stack->dummy_node;
	node = from_dummy_node->next;
	top = to_dummy_node->next;
	if (node == from_dummy_node)
		return ;
	from_dummy_node->next = node->next;
	node->next->prev = from_dummy_node;
	from_stack->size--;
	node->prev = to_dummy_node;
	node->next = top;
	top->prev = node;
	to_dummy_node->next = node;
	to_stack->size++;
}

void	push_b(t_stack *stk_b, t_stack *stk_a)
{
	push(stk_b, stk_a);
	ft_printf(PUSH_B);
}

void	push_a(t_stack *stk_a, t_stack *stk_b)
{
	push(stk_a, stk_b);
	ft_printf(PUSH_A);
}
