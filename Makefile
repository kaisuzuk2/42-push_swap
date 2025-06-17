# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/08 19:14:13 by kaisuzuk          #+#    #+#              #
#    Updated: 2025/06/18 00:40:26 by kaisuzuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
B_NAME = checker
CC = cc
FLAG = -Wall -Wextra -Werror
MAKE = make -C
RM = rm -rf
DEBUG = -g -fsanitize=address 
SRCS = error_check.c\
		push.c\
		rotate_helper.c\
		rotate.c\
		swap.c\
		stack_utils.c\
		compression.c\
		sort_three.c\
		sort_five.c\
		operation_helper.c\
		cost_utils.c\
		cost_utils_helper.c\
		push_back.c\
		sort.c\
		free_list.c
B_SRCS = add_operator_bonus.c

OBJS = $(SRCS:%.c=%.o)
B_OBJS = $(B_SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(SRCS)
	$(MAKE) ./printf
	cp ./printf/libftprintf.a .
	$(CC) $(FLAG) -o $(NAME) main.c $(SRCS) libftprintf.a

%.o: %.c
	$(CC) $(FLAG) -c -o $@ $<

bonus:
	ar -d libftprintf.a ft_strchr.o ft_strdup.o ft_strjoin.o ft_strlen.o

	$(MAKE) ./get_next_line
	cp ./get_next_line/gnl.a .

	$(CC) $(FLAG) -o $(B_NAME) main_bonus.c $(SRCS) $(B_SRCS) libftprintf.a gnl.a
	
clean:
	$(MAKE) ./printf clean	
	$(MAKE) ./get_next_line clean
	$(RM) $(OBJS)
	$(RM) $(B_OBJS)	
fclean: clean
	$(MAKE) ./printf fclean
	$(MAKE) ./get_next_line fclean
	$(RM) libftprintf.a
	$(RM) gnl.a
	$(RM) $(NAME)
	$(RM) $(B_NAME)
	
re: fclean all

.PHONY: all clean fclean re bonus