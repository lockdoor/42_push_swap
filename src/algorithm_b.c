/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:30:23 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/10 10:17:51 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
** this group of function is calculate times by t_cal
** it' calculate index of a and b for count rotate times
** and get size of stack for calculate by reverse rotate
** then set instruct in t_cal and count times spend each algorithm
*/
void	rs(t_cal *tmp)
{
	set_zero_rotate (tmp);
	if (tmp->idx_a > tmp->idx_b)
	{
		tmp->rs = tmp->idx_b;
		tmp->ra = tmp->idx_a - tmp->idx_b;
		tmp->rb = 0;
	}
	else
	{
		tmp->rs = tmp->idx_a;
		tmp->rb = tmp->idx_b - tmp->idx_a;
		tmp->ra = 0;
	}
	tmp->cnt = count_operate (tmp);
}

void	rrs(t_cal *tmp)
{
	size_t	idx_a;
	size_t	idx_b;

	set_zero_rotate (tmp);
	idx_a = tmp->len_a - tmp->idx_a;
	idx_b = tmp->len_b - tmp->idx_b;
	if (idx_a > idx_b)
	{
		tmp->rrs = idx_b;
		tmp->rra = idx_a - idx_b;
		tmp->rrb = 0;
	}
	else
	{
		tmp->rrs = idx_a;
		tmp->rrb = idx_b - idx_a;
		tmp->rra = 0;
	}
	tmp->cnt = count_operate (tmp);
}

void	rotate_min(t_cal *tmp)
{
	set_zero_rotate (tmp);
	if (tmp->idx_a > tmp->len_a / 2)
		tmp->rra = tmp->len_a - tmp->idx_a;
	else
		tmp->ra = tmp->idx_a;
	if (tmp->idx_b > tmp->len_b / 2)
		tmp->rrb = tmp->len_b - tmp->idx_b;
	else
		tmp->rb = tmp->idx_b;
	tmp->cnt = count_operate (tmp);
}

void	rarrb(t_cal *tmp)
{
	set_zero_rotate(tmp);
	tmp->ra = tmp->idx_a;
	tmp->rrb = tmp->len_b - tmp->idx_b;
	tmp->cnt = count_operate (tmp);
}

void	rrarb(t_cal *tmp)
{
	set_zero_rotate(tmp);
	tmp->rra = tmp->len_a - tmp->idx_a;
	tmp->rb = tmp->idx_b;
	tmp->cnt = count_operate (tmp);
}
