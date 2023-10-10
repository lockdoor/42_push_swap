# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 10:14:06 by pnamnil           #+#    #+#              #
#    Updated: 2023/10/10 08:09:59 by pnamnil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker

LIBFT_PATH = libft
INCLUDE = $(LIBFT_PATH)/includes
LIBFT = -L$(LIBFT_PATH) -lft

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDE)

SRCS = $(addprefix src/, push_swap.c debug.c lisc_utils.c init_stack.c\
	sort_stack.c check_condition.c find_position.c\
	push_b.c algorithm_b.c operate_a_b.c helper.c parse_args.c\
	operate_sw.c operate_r.c operate_rr.c operate_p.c)
OBJS = $(patsubst src/%.c, bin/%.o, $(SRCS))

B_SRCS = $(addprefix src/, checker.c lisc_utils.c init_stack.c parse_args.c\
	operate_p.c operate_r.c operate_rr.c operate_sw.c check_condition.c\
	find_position.c)
B_OBJS = $(patsubst src/%.c, bin/%.o, $(B_SRCS))


bin/%.o: src/%.c
	@mkdir -p bin
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

bonus:	$(CHECKER)

$(CHECKER): $(B_OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(LIBFT) $(B_OBJS) -o $(CHECKER)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(LIBFT) -lft $(OBJS) -o $(NAME)

clean:
	rm -rf bin
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re
