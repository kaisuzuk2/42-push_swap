/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:48:00 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/20 18:32:39 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr);

t_bool	ft_is_sort(const int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] != arr[i + 1] - 1)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	ft_is_digit(char **argv, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		if (argv[i][j] == '\0')
			return (1);
		if (argv[i][j] == '+' || argv[i][j] == '-')
		{
			j++;
			if (argv[i][j] == '\0')
				return (FALSE);
		}
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

t_bool	ft_is_duplicates(const int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	*char_to_int(char **argv, int size)
{
	int		i;
	int		*res;
	long	tmp;

	res = malloc(sizeof(int) * size);
	if (!res)
		return (NULL);
	i = 1;
	while (i < size)
	{
		tmp = ft_atol(argv[i]);
		if (tmp < INT_MIN || INT_MAX < tmp)
			return (ft_printf(ERROR), free(res), NULL);
		res[i - 1] = (int)tmp;
		i++;
	}
	return (res);
}
