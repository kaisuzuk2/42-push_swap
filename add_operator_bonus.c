/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_operator_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:02:54 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/10 17:17:57 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_stack *stk);

void	swap_b(t_stack *stk_b)
{
	swap(stk_b);
	ft_printf(SWAP_B);
}

void	swap_both(t_stack *stk_a, t_stack *stk_b)
{
	swap(stk_a);
	swap(stk_b);
	ft_printf(SWAP_BOTH);
}
