/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:22:34 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/11 06:47:11 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <unistd.h>

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"
# define PA "pa\n"
# define PB "pb\n"

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

// init_stack
void	init_stack(int argc, char **argv, t_stack *sta);

// parse_args
t_bool	parse_args(int argc, char **argv, t_list **lst);

// check_condition
t_bool	is_sort(t_stack *st);

// lisc_utils
t_lstc	*newlstc(int n);
void	lstc_clear(t_lstc **lst);
void	lstc_add_back(t_lstc **lst, t_lstc *new);

// find_position
t_bool	find_min(int a, int b);
t_bool	find_max(int a, int b);
size_t	find_pos(t_stack *st, t_lstc *to_find);
size_t	find_right_position_stack_b(t_stack *st, int n);
t_lstc	*find_min_max(t_stack *st, t_bool (*find)(int, int));

// operate
void	operate_swap(t_stack *st, t_bool print);
void	operate_ss(t_stack *sta, t_stack *stb, t_bool print);
void	operate_r(t_stack *st, t_bool print);
void	operate_rs(t_stack *sta, t_stack *stb, t_bool print);
void	operate_rr(t_stack *st, t_bool print);
void	operate_rrs(t_stack *sta, t_stack *stb, t_bool print);
void	operate_push(t_stack *from, t_stack *to, t_bool print);

// helper
void	ft_free_split(char **sp);

#endif
