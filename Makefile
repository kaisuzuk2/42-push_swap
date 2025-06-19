# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/08 19:14:13 by kaisuzuk          #+#    #+#              #
#    Updated: 2025/06/19 17:00:41 by kaisuzuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
B_NAME = checker
CC = cc
FLAG = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address 

LIB_PATH = ./printf
GNL_PATH = ./get_next_line

MAKE = make -C
CP = cp
RM = rm -rf

LIB = libftprintf.a
GNL = get_next_line.a

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
MAIN = main.c
B_SRCS = add_operator_bonus.c
B_MAIN = main_bonus.c

OBJS = $(SRCS:%.c=%.o)
B_OBJS = $(B_SRCS:%.c=%.o)

all: $(NAME)

$(NAME): main.o $(OBJS) $(LIB)
	$(CC) $(FLAG) -o $(NAME) main.o $(OBJS) $(LIB)

%.o: %.c
	$(CC) $(FLAG) -c -o $@ $<

bonus: $(B_NAME)

$(B_NAME): main_bonus.o $(B_OBJS) $(LIB) $(GNL)
	$(CC) $(FLAG) -o $(B_NAME) main_bonus.o $(B_OBJS) $(OBJS) $(LIB) $(GNL)
	
$(LIB): 
	$(MAKE) $(LIB_PATH)
	$(CP) $(LIB_PATH)/$(LIB) .

$(GNL):
	$(MAKE) $(GNL_PATH)
	$(CP) $(GNL_PATH)/$(GNL) .

clean:
	$(MAKE) $(LIB_PATH) clean	
	$(MAKE) $(GNL_PATH) clean
	$(RM) $(OBJS)
	$(RM) main.o
	$(RM) $(B_OBJS)
	$(RM) main_bonus.o	
	
fclean: clean
	$(MAKE) $(LIB_PATH) fclean
	$(MAKE) $(GNL_PATH) fclean
	$(RM) $(LIB)
	$(RM) $(GNL)
	$(RM) $(NAME)
	$(RM) $(B_NAME)
	
re: fclean all

.PHONY: all clean fclean re bonus