/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:42:46 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/09 00:59:35 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	*ft_intarr_cpy(int *dest, const int *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

static void	quick_sort(int *arr, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	if (left >= right)
		return ;
	pivot = arr[left];
	i = left;
	j = right;
	while (1)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i >= j)
			break ;
		ft_swap(&arr[i], &arr[j]);
		i++;
		j--;
	}
	quick_sort(arr, left, j);
	quick_sort(arr, j + 1, right);
}

static void	make_rank_arr(int *rank_arr, int *arr, int *sorted_arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (arr[i] != sorted_arr[j])
			j++;
		rank_arr[i] = (j + 1);
		i++;
	}
}

int	*compression(int *arr, int size)
{
	int	*rank_arr;
	int	*sorted_arr;

	rank_arr = (int *)malloc(sizeof(int) * size);
	sorted_arr = (int *)malloc(sizeof(int) * size);
	if (!rank_arr || !sorted_arr)
	{
		free(rank_arr);
		free(sorted_arr);
		return (NULL);
	}
	ft_intarr_cpy(sorted_arr, arr, size);
	quick_sort(sorted_arr, 0, size - 1);
	make_rank_arr(rank_arr, arr, sorted_arr, size);
	ft_intarr_cpy(arr, rank_arr, size);
	free(sorted_arr);
	free(rank_arr);
	return (arr);
}
