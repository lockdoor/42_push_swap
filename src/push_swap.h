/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:46:48 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/11 06:45:05 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include "libft.h"
# define BUF_SIZE 500
# define DEBUG_MODE 0

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
	struct s_lstc	*max;
	struct s_lstc	*min;
	char			name;
}	t_stack;

typedef struct s_cal
{
	int		n;
	size_t	cnt;
	size_t	ra;
	size_t	rb;
	size_t	rra;
	size_t	rrb;
	size_t	rs;
	size_t	rrs;
	t_bool	min;
	t_bool	max;
	size_t	idx_a;
	size_t	idx_b;
	size_t	len_a;
	size_t	len_b;
}	t_cal;

// debug
void	printf_lst(t_lstc *lst, size_t size);
void	printf_stack(t_lstc *lsta, t_lstc *lstb, size_t a, size_t b);
void	print_cal(t_cal *cal);
void	printf_one_stack(t_stack *st);
void	printSprit(char **nb);

// operate
void	operate_swap(t_stack *st, t_bool print);
void	operate_ss(t_stack *sta, t_stack *stb, t_bool print);
void	operate_r(t_stack *st, t_bool print);
void	operate_rs(t_stack *sta, t_stack *stb, t_bool print);
void	operate_rr(t_stack *st, t_bool print);
void	operate_rrs(t_stack *sta, t_stack *stb, t_bool print);
void	operate_push(t_stack *from, t_stack *to, t_bool print);

// find_position
t_bool	find_min(int a, int b);
t_bool	find_max(int a, int b);
size_t	find_pos(t_stack *st, t_lstc *to_find);
size_t	find_right_position_stack_b(t_stack *st, int n);
t_lstc	*find_min_max(t_stack *st, t_bool (*find)(int, int));

// push_b
void	push_b_until(t_stack *sta, t_stack *stb);

// algorithm_b
void	rs(t_cal *tmp);
void	rrs(t_cal *tmp);
void	rotate_min(t_cal *tmp);
void	rarrb(t_cal *tmp);
void	rrarb(t_cal *tmp);

// oprate_a_b
void	operate_by_champ(t_cal *cal, t_stack *sta, t_stack *stb);
void	operate_rotate(size_t cnt, t_stack *st, \
		void (*operate)(t_stack *, t_bool));

// helper
void	set_zero_rotate(t_cal *tmp);
size_t	count_operate(t_cal *c);
void	init_error_exit(t_stack *sta, t_list **lst);
void	ft_free_split(char **sp);

// check_condition
t_bool	is_sort(t_stack *st);
t_bool	lstca_is_sort(t_stack *st);
t_bool	lstcb_is_sort(t_stack *st);

// lisc_utils
t_lstc	*newlstc(int n);
void	lstc_clear(t_lstc **lst);
void	lstc_add_back(t_lstc **lst, t_lstc *new);

// init_stack
void	init_stack(int argc, char **argv, t_stack *sta);

//sort_stack
void	sort_stack(t_stack *sta);

// parse_args
t_bool	parse_args(int argc, char **argv, t_list **lst);

#endif
