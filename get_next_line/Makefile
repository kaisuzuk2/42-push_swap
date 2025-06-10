# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/10 17:19:57 by kaisuzuk          #+#    #+#              #
#    Updated: 2025/06/10 17:21:51 by kaisuzuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = gnl.a
CC = cc
FLAG = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address 
SRCS = get_next_line.c\
		get_next_line_utils.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAG) -c -o $@ $<

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
	
re: fclean all

.PHONY: all clean fclean re