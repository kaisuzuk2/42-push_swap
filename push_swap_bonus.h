/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:03:35 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/06/10 17:45:36 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

# define SWAP_B "sb\n"
# define SWAP_BOTH "ss\n"

# define SUCCESS "OK\n"
# define FAIL "KO\n"

# define PROGRAM_ERROR 2

// libft
int		ft_strncmp(const char *s1, const char *s2, size_t n);
// get_next_line
char	*get_next_line(int fd);
// stack op
void	swap_b(t_stack *stk_b);
void	swap_both(t_stack *stkk_a, t_stack *stk_b);

// operator
void	rotate(t_stack *stk);
void	push(t_stack *to_stack, t_stack *from_stack);
void	swap(t_stack *stk);
void	reverse_rotate(t_stack *stk);

#endif