/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:55:24 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/20 18:37:21 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_is_digit(char **argv, int size);
t_bool	ft_is_sort(const int *arr, int size);
t_bool	ft_is_duplicates(const int *arr, int size);
long	ft_atol(const char *nptr);
int		*char_to_int(char **argv, int size);

int	main(int argc, char **argv)
{
	int	*arr;
	int	return_val;

	if (!ft_is_digit(argv, argc))
		return (ft_printf(ERROR), EXIT_USER_ERROR);
	arr = char_to_int(argv, argc);
	if (!arr)
		return (EXIT_MALLOC_ERROR);
	if (argc <= 2)
		return (0);
	if (!compression(arr, argc - 1))
		return (EXIT_MALLOC_ERROR);
	if (!ft_is_duplicates(arr, argc - 1))
		return (free(arr), ft_printf(ERROR), EXIT_USER_ERROR);
	if (ft_is_sort(arr, argc - 1))
		return (free(arr), 0);
	return_val = sort_operator(arr, argc - 1);
	free(arr);
	return (return_val);
}
