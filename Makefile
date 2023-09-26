# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 10:14:06 by pnamnil           #+#    #+#              #
#    Updated: 2023/09/26 13:23:31 by pnamnil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_PATH = libft
INCLUDE = $(LIBFT_PATH)/includes

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDE)

SRCS = main.c debug.c init_stack.c
OBJS = $(patsubst %.c, bin/%.o, $(SRCS))

bin/%.o: %.c
	@mkdir -p bin
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)
	./$(NAME)
	
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
