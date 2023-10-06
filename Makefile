# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 10:14:06 by pnamnil           #+#    #+#              #
#    Updated: 2023/10/06 11:39:08 by pnamnil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_PATH = libft
INCLUDE = $(LIBFT_PATH)/includes

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDE)

SRCS = $(addprefix src/, push_swap.c debug.c lisc_utils.c init_stack.c\
	sort_stack.c check_condition.c operate.c find_position.c\
	push_b.c algorithm_b.c operate_a_b.c helper.c)
OBJS = $(patsubst src/%.c, bin/%.o, $(SRCS))

bin/%.o: src/%.c
	@mkdir -p bin
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)
	./$(NAME)

leak:
	leaks --atExit -- ./$(NAME)

cnt:
	./$(NAME) | wc -l
	
$(NAME): libft_make $(OBJS)
	$(CC) $(CFLAGS) -L$(LIBFT_PATH) -lft $(OBJS) -o $(NAME)
	
libft_make:
	$(MAKE) -C $(LIBFT_PATH)

clean:
	rm -rf bin

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all libft_make clean fclean re
