/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:48:58 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/10 17:16:40 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stk)
{
	t_node	*top;
	t_node	*new_top;
	t_node	*dummy_node;

	dummy_node = stk->dummy_node;
	top = dummy_node->next;
	new_top = top->next;
	if (top == dummy_node || new_top == dummy_node)
		return ;
	dummy_node->next = new_top;
	new_top->prev = dummy_node;
	top->prev = new_top;
	top->next = new_top->next;
	new_top->next->prev = top;
	new_top->next = top;
}

void	swap_a(t_stack *stk_a)
{
	swap(stk_a);
	ft_printf(SWAP_A);
}
