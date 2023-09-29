/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:46:48 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/28 17:02:07 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include "libft.h"

# define ERR_MESSAGE ft_printf ("Error\n");
// # define PRINT_STACK printf_stack (sta->head, stb->head, sta->size, stb->size);
# define PRINT_STACK

typedef struct s_lstc
{
	struct s_lstc	*next;
	struct s_lstc	*prev;
	int				n;
}	t_lstc;

typedef struct s_stack
{
	struct s_lstc	*head;
	size_t			size;
	char			name;
}	t_stack;

// debug
void	printf_lst(t_lstc *lst, size_t size);
void	printf_stack(t_lstc *lsta, t_lstc *lstb, size_t a, size_t b);

// init_stack
t_lstc	*newlstc(int n);
void	lstc_clear(t_lstc **lst);
void	lstc_add_back(t_lstc **lst, t_lstc *new);
void	init_stack(int *nb, size_t nb_len, t_stack **sta, t_stack **stb);

// operate
void	operate_swap(t_stack *st);
void	operate_ss(t_stack *sta, t_stack *stb);
void	operate_r(t_stack *st);
void	operate_rs(t_stack *sta, t_stack *stb);
void	operate_rr(t_stack *st);
void	operate_rrs(t_stack *sta, t_stack *stb);
void	operate_push(t_stack *from, t_stack *to);

#endif
