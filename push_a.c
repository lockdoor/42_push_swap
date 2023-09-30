/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:55:51 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/30 16:11:11 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_min_pos(t_stack *st)
{
	size_t	pos;
	
	pos = find_pos(st, st->min);
	// if (st->head->n == 175)
	// 	ft_printf ("min posision: %d\n", (int)pos);
	if (pos == 0)
		return ;
	if (pos > st->size / 2)
	{
		pos = st->size - pos;
		operate_rotate (pos, st, operate_rr);
	}
	else
	{
		operate_rotate (pos, st, operate_r);
	}
}

void	push_a(t_stack *sta, t_stack *stb)
{
	while (stb->size)
	{
		if (stb->head->n > sta->max->n || stb->head->n < sta->min->n)
		{
			rotate_min_pos (sta);
			if (stb->head->n > sta->max->n)
				sta->max = stb->head;
			else
				sta->min = stb->head;
		}
		else if (stb->head->n < sta->head->prev->n)
		{
			while (stb->head->n < sta->head->prev->n)
				operate_rr (sta);
		}
		else if (stb->head->n > sta->head->n)
		{
			while (stb->head->n > sta->head->n)
				operate_r (sta);
		}	
		operate_push (stb, sta);		
		PRINT_STACK
	}
	rotate_min_pos (sta);
}
