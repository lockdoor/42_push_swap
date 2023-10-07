/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:33:26 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/07 15:30:56 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_three(t_stack *st)
{
	int	n[3];
	n[0] = st->head->n;
	n[1] = st->head->next->n;
	n[2] = st->head->prev->n;
	if (n[0] < n[1] && n[0] < n[2] && n[2] < n[1])
	{
		operate_swap (st);
		operate_r (st);
	}
	else if (n[0] > n[1] && n[1] > n[2] && n[2] < n[1])
	{
		operate_swap (st);
		operate_rr (st);
	}
	else if (n[0] > n[1] && n[1] < n[2] && n[0] > n[2])
		operate_r (st);
	else if (n[0] < n[1] && n[0] > n[2] && n[2] < n[0])
		operate_rr (st);
	else if (n[0] > n[1] && n[1] < n[2] && n[2] > n[0])
		operate_swap (st);
	st->min = st->head;
	st->max = st->head->prev;
}

void	operate_push_a(t_cal *cal, t_stack *sta, t_stack *stb)
{
	if (cal->idx_a > cal->len_a / 2)
		operate_rotate (cal->len_a - cal->idx_a, sta, operate_rr);
	else
		operate_rotate (cal->idx_a, sta, operate_r);
	operate_push (stb, sta);
	if (cal->max)
		sta->max = sta->head;
	if (cal->min)
		sta->min = sta->head;
}

size_t	find_right_position_stack_a(t_stack *sta, int n)
{
	size_t	i;
	t_lstc	*node;
	
	i = 0;
	node = sta->head;
	while (i < sta->size)
	{
		if (n < node->n && n > node->prev->n)
			break ;
		i++ ;
		node = node->next;
	}
	return (i);
}

void	push_a_util(t_stack *sta, t_stack *stb)
{
	t_cal	cal;

	sta->max = find_min_max (sta, find_max);
	sta->min = find_min_max (sta, find_min);
	while (stb->size)
	{
		ft_memset(&cal, 0, sizeof(t_cal));
		cal.len_a = sta->size;
		cal.n = stb->head->n;
		if (cal.n > sta->max->n || cal.n < sta->min->n)
		{
			cal.idx_a = find_pos (sta, sta->min);
			if (cal.n > sta->max->n)
				cal.max = TRUE;
			else
				cal.min = TRUE;
		}
		else
		{
			cal.idx_a = find_right_position_stack_a (sta, cal.n);
		}
		operate_push_a (&cal, sta, stb);
		
		if (DEBUG_MODE)		
		{
			PRINT_STACK
			if (!lstca_is_sort(sta))
			{
				ft_printf ("min: %d, max: %d, index: %d\n", sta->min->n, sta->max->n, (int)cal.idx_a);
				printf_stack (sta->head, stb->head, sta->size, stb->size);
				exit(1);
			}		
		}
	}
}

void    sort_stack(t_stack  *sta)
{
	t_stack stb;
	size_t	index;

	if (sta->size == 2)
	{
		if (sta->head->n > sta->head->next->n)
			operate_swap (sta);
		return ;
	}
	ft_memset (&stb, 0, sizeof(t_stack));
	stb.name = 'b';
	if (sta->size > 3 && !lstca_is_sort(sta))
		operate_push (sta, &stb);
	if (sta->size > 3 && !lstca_is_sort(sta))
		operate_push (sta, &stb);
	if (sta->size > 3 && !lstca_is_sort(sta))
		push_b_until (sta, &stb);
	if (sta->size == 3 && !lstca_is_sort(sta))
		solve_three (sta);
	if (stb.size)
		push_a_util (sta, &stb);

	// if have 2 number it not have min max
	if (!is_sort(sta))
	{
		index = find_pos(sta, sta->min);
		if (index > sta->size / 2)
			operate_rotate(sta->size - index, sta, operate_rr);
		else
			operate_rotate(index, sta, operate_r);
	}
}
