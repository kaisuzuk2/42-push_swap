/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:33:56 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/08 19:08:51 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack *stk)
{
	t_node	*cur;
	t_node	*dummy_node;
	t_node	*tmp;

	if (stk == NULL)
		return ;
	dummy_node = stk->dummy_node;
	cur = dummy_node->next;
	while (cur != dummy_node)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	free(dummy_node);
	free(stk);
}
