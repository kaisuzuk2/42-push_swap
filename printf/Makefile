# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 16:23:46 by kaisuzuk          #+#    #+#              #
#    Updated: 2025/05/08 16:49:22 by kaisuzuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
MAKE = make
CC = cc -Wall -Werror -Wextra -Iincludes
_SRCS = ft_printf.c \
		ft_printf_p.c\
		ft_printf_u.c\
		ft_printf_x.c \
		ft_printf_c.c
		
_BSRCS = ft_printf_bonus.c \
		ft_printf_set_flg_prec_bonus.c \
		ft_printf_set_utils_bonus.c \
		ft_printf_di_bonus.c  \
		ft_printf_c_bonus.c \
		ft_printf_s_bonus.c \
		ft_printf_u_bonus.c \
		ft_printf_p_bonus.c \
		ft_printf_x_bonus.c \
		ft_putnchar_bonus.c
		
SRCS = $(patsubst %, srcs/%, $(_SRCS))
BSRCS = $(patsubst %, bonus/%, $(_BSRCS))
OBJS = $(SRCS:%.c=%.o)
BOBJS = $(BSRCS:%.c=%.o)

all: $(NAME)
	
$(NAME): $(OBJS) 
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

bonus : $(BOBJS)
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(BOBJS)

%.o: %.c
	$(CC) -c -o $@  $<

clean :
	$(MAKE) -C ./libft clean
	rm -rf $(OBJS)
	rm -rf $(BOBJS)

fclean : clean
	$(MAKE) -C ./libft fclean
	rm -rf $(NAME)

re : clean fclean all

.PHONY: clean fclean bonus all
	