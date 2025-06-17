/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:36:08 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/18 00:43:33 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int			ft_is_digit(char **argv, int size);
int			ft_is_sort(const int *arr, int size);
int			ft_is_duplicates(const int *arr, int size);
long		ft_atol(const char *nptr);
int			ft_is_list_sort(t_stack *stk_a);
int			*char_to_int(char **argv, int size);

static int	checker_op(t_stack *stk_a, t_stack *stk_b, char *read_val)
{
	if (!ft_strncmp(read_val, SWAP_A, 3))
		swap(stk_a);
	else if (!ft_strncmp(read_val, SWAP_B, 3))
		swap(stk_b);
	else if (!ft_strncmp(read_val, SWAP_BOTH, 3))
		(swap(stk_a), swap(stk_b));
	else if (!ft_strncmp(read_val, PUSH_A, 3))
		push(stk_a, stk_b);
	else if (!ft_strncmp(read_val, PUSH_B, 3))
		push(stk_b, stk_a);
	else if (!ft_strncmp(read_val, ROTATE_A, 3))
		rotate(stk_a);
	else if (!ft_strncmp(read_val, ROTATE_B, 3))
		rotate(stk_b);
	else if (!ft_strncmp(read_val, ROTATE_BOTH, 3))
		(rotate(stk_a), rotate(stk_b));
	else if (!ft_strncmp(read_val, REVERSE_ROTATE_A, 4))
		reverse_rotate(stk_a);
	else if (!ft_strncmp(read_val, REVERSE_ROTATE_B, 4))
		reverse_rotate(stk_b);
	else if (!ft_strncmp(read_val, REVERSE_ROTATE_BOTH, 4))
		(reverse_rotate(stk_a), reverse_rotate(stk_b));
	else
		return (ft_printf(ERROR), PROGRAM_ERROR);
	return (0);
}

static int	checker(int *arr, int size)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	char	*read_val;

	read_val = NULL;
	stk_a = stack_utils(arr, size);
	stk_b = make_stack();
	if (!stk_a || !stk_b)
		return (free_list(stk_a), free_list(stk_b), EXIT_MALLOC_ERROR);
	read_val = get_next_line(0);
	while (read_val)
	{
		if (checker_op(stk_a, stk_b, read_val))
			return (PROGRAM_ERROR);
		free(read_val);
		read_val = get_next_line(0);
	}
	if (stk_b->size || !ft_is_list_sort(stk_a))
		return (ft_printf(FAIL), 0);
	ft_printf(SUCCESS);
	free_list(stk_a);
	free_list(stk_b);
	return (0);
}

int	main(int argc, char **argv)
{
	int			*arr;
	int			return_val;
	const int	size = argc - 1;

	if (argc <= 2)
		return (0);
	if (ft_is_digit(argv, argc))
		return (ft_printf(ERROR), EXIT_USER_ERROR);
	arr = char_to_int(argv, argc);
	if (!arr)
		return (EXIT_MALLOC_ERROR);
	if (!compression(arr, size))
		return (EXIT_MALLOC_ERROR);
	if (ft_is_duplicates(arr, size))
		return (free(arr), ft_printf(ERROR), EXIT_USER_ERROR);
	return_val = checker(arr, size);
	free(arr);
	return (return_val);
}
