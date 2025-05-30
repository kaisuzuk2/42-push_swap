#include "push_swap.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int			*p;
	const int	*s;
	size_t		i;

	p = (int *)dest;
	s = (const int *)src;
	i = 0;
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	return (dest);
}

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	quick_sort(int *arr, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	i = left;
	j = right;
	if (i >= j)
		return ;
	pivot = arr[left];
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


int *make_rank_array(int *arr, int size)
{
	int	*sorted_arr;
	int	*rank;
	int	i;
	int	j;

	sorted_arr = (int *)malloc(sizeof(int) * size);
	rank = (int *)malloc(sizeof(int) * size);
	ft_memcpy(sorted_arr, arr, size);
	quick_sort(sorted_arr, 0, size - 1);
	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size && arr[i] != sorted_arr[j])
			j++;
		rank[i] = j;
		i++;
	}
	free(sorted_arr);
	return (rank);
}
