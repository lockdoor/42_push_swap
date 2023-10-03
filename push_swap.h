/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:46:48 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/02 11:10:24 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include "libft.h"

# define ERR_MESSAGE ft_printf ("Error\n");
# define PRINT_STACK printf_stack (sta->head, stb->head, sta->size, stb->size);
// # define PRINT_STACK ;

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
	struct s_lstc	*mark;
	struct s_lstc	*max;
	struct s_lstc	*min;
	size_t			mark_pos;
	char			name;
}	t_stack;

typedef struct	s_cal
{
	int		n;
	size_t	cnt;
	size_t	push;
	size_t	ra;
	size_t	rb;
	size_t	rra;
	size_t	rrb;
	size_t	rs;
	size_t	rrs;
	t_bool	min;
	t_bool	max;
}	t_cal;

// debug
void	printf_lst(t_lstc *lst, size_t size);
void	printf_stack(t_lstc *lsta, t_lstc *lstb, size_t a, size_t b);
void	print_cal (t_cal *cal);

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

// find_position
t_bool	find_min (int a, int b);
t_bool	find_max (int a, int b);
void	find_position (t_stack *st, t_bool (*find)(int, int));
size_t	find_pos (t_stack *st, t_lstc *to_find);
size_t	find_right_position_stack_b(t_stack *st, int n);

// calculate
void	init_cal (t_cal *cal);
void	cnt_candidate (t_cal *cdd);
void	set_cheep (t_cal *cheep, t_cal *candidate);

// push_b
void	push_b (t_stack *sta, t_stack *stb);
void	operate_rotate (size_t cnt, t_stack *st, void(*operate)(t_stack *));

// push_a
void	push_a (t_stack *sta, t_stack *stb);

// check_condition
t_bool	is_sort (t_stack *st);
t_bool	lstc_is_sort(t_stack *st);

// solve
void	solve_three (t_stack *st);
void	solve (t_stack *sta, t_stack *stb);

// utils
void make_numbers_no_dup (int *nb, size_t size);

#endif
