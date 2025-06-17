/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:08:32 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/18 00:29:30 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_sort(t_stack *stk_a, t_stack *stk_b)
{
	t_cost	*cst;

	cst = calc_cost(stk_a, stk_b);
	if (!cst)
		return (1);
	while (cst->rr)
		(rotate_both(stk_a, stk_b), cst->rr--);
	while (cst->rrr)
		(reverse_rotate_both(stk_a, stk_b), cst->rrr--);
	while (cst->ra)
		(rotate_a(stk_a), cst->ra--);
	while (cst->rb)
		(rotate_b(stk_b), cst->rb--);
	while (cst->rra)
		(reverse_rotate_a(stk_a), cst->rra--);
	while (cst->rrb)
		(reverse_rotate_b(stk_b), cst->rrb--);
	free(cst);
	return (0);
}

static int	sort(t_stack *stk_a, t_stack *stk_b)
{
	int	sort_limit;

	if (stk_a->size >= 500)
		sort_limit = 30;
	else
		sort_limit = 5;
	while (stk_b->size < 2)
		push_b(stk_b, stk_a);
	while (stk_a->size > sort_limit)
	{
		if (do_sort(stk_a, stk_b))
			return (EXIT_MALLOC_ERROR);
		push_b(stk_b, stk_a);
	}
	sort_five(stk_a, stk_b);
	push_back(stk_a, stk_b);
	return (0);
}

int	sort_operator(int *arr, int size)
{
	t_stack	*stk_a;
	t_stack	*stk_b;

	stk_a = stack_utils(arr, size);
	stk_b = make_stack();
	if (!stk_a || !stk_b)
		return (free_list(stk_a), free_list(stk_b), EXIT_MALLOC_ERROR);
	if (stk_a->size <= 3)
		sort_three(stk_a);
	else if (stk_a->size <= 5)
		sort_five(stk_a, stk_b);
	else if (sort(stk_a, stk_b))
		return (free_list(stk_a), free_list(stk_b), EXIT_MALLOC_ERROR);
	return (free_list(stk_a), free_list(stk_b), 0);
}
