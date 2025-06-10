/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:27:03 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/10 18:07:13 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_cost_pear(t_cost *cst)
{
	int			min;
	const int	rarb = cst->ra + cst->rb;
	const int	rarrb = cst->ra + cst->rrb;
	const int	rrarb = cst->rra + cst->rb;
	const int	rrarrb = cst->rra + cst->rrb;

	min = rarb;
	if (rarrb < min)
		min = rarrb;
	if (rrarb < min)
		min = rrarb;
	if (rrarrb < min)
		min = rrarrb;
	return (min);
}

t_cost	*calc_optimization_helper(t_cost *cst)
{
	int	min;

	min = min_cost_pear(cst);
	if (min == cst->ra + cst->rb)
	{
		cst->rra = 0;
		cst->rrb = 0;
	}
	else if (min == cst->ra + cst->rrb)
	{
		cst->rra = 0;
		cst->rb = 0;
	}
	else if (min == cst->rra + cst->rb)
	{
		cst->ra = 0;
		cst->rrb = 0;
	}
	else
	{
		cst->ra = 0;
		cst->rb = 0;
	}
	return (cst);
}
