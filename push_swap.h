/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:46:48 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/26 15:28:00 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include "libft.h"

# define ERR_MESSAGE "Error\n"

typedef struct s_lstc
{
	struct s_lstc	*next;
	struct s_lstc	*prev;
	int				n;
}	t_lstc;

typedef struct s_stack
{
	struct s_lstc	*head;
	int				min;
	int				max;
	int				min_pos;
	int				max_pos;
	int				size;
}	t_stack;

// debug
void	printf_lst(t_lstc *lst);

// init_stack
t_lstc	*newlstc(int n);
void	lstc_clear(t_lstc **lst);
void	lstc_add_back(t_lstc **lst, t_lstc *new);
t_stack	*init_stack(int *nb, int nb_len);

#endif
