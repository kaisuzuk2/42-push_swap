#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>

typedef struct s_stack {
	int rank;
	struct s_stack *prev;
	struct s_stack *next;
} t_stack;

int	ft_isdigit(int c);
int	ft_atoi(const char *nptr);


#endif 