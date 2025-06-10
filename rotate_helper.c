/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:38:11 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/08 16:41:02 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stk);
void	reverse_rotate(t_stack *stk);

void	rotate_a(t_stack *stk_a)
{
	if (stk_a == NULL)
		return ;
	rotate(stk_a);
	ft_printf(ROTATE_A);
}

void	rotate_b(t_stack *stk_b)
{
	if (stk_b == NULL)
		return ;
	rotate(stk_b);
	ft_printf(ROTATE_B);
}

void	reverse_rotate_a(t_stack *stk_a)
{
	if (stk_a == NULL)
		return ;
	reverse_rotate(stk_a);
	ft_printf(REVERSE_ROTATE_A);
}

void	reverse_rotate_b(t_stack *stk_b)
{
	if (stk_b == NULL)
		return ;
	reverse_rotate(stk_b);
	ft_printf(REVERSE_ROTATE_B);
}
