#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>

typedef struct s_stack {
	int rank;
	struct s_stack *prev;
	struct s_stack *next;
	int size;
} t_stack;

typedef struct s_cost {
	int ra;
	int rra;
	int rb;
	int rrb;
	int rr;
	int rrr;
} t_cost;


int	ft_isdigit(int c);
int	ft_atoi(const char *nptr);


t_cost	*calc_cost(t_stack *stk_a, t_stack *stk_b);

t_stack *stack_utils(int *arr, int size);
int *make_rank_array(int *arr, int size);

void	do_sort(t_cost *cst, t_stack *stk_a, t_stack *stk_b);

void push(t_stack *to_stack, t_stack *from_stack);
void	reverse_rotate(t_stack *stack);
void	rotate(t_stack *stack);
void	swap(t_stack *stack);

#endif 