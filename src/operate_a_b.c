/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_a_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:38:37 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/09 14:51:56 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operate_rotate(size_t cnt, t_stack *st,
	void (*operate)(t_stack *, t_bool))
{
	while (cnt)
	{
		operate (st, TRUE);
		cnt-- ;
	}
}

static void	operate_rotate_db(size_t cnt, t_stack *sta, t_stack *stb,
	void (*operate)(t_stack *, t_stack *, t_bool))
{
	while (cnt)
	{
		operate (sta, stb, TRUE);
		cnt-- ;
	}
}

void	operate_by_champ(t_cal *cal, t_stack *sta, t_stack *stb)
{
	operate_rotate_db (cal->rs, sta, stb, operate_rs);
	operate_rotate_db (cal->rrs, sta, stb, operate_rrs);
	operate_rotate (cal->ra, sta, operate_r);
	operate_rotate (cal->rb, stb, operate_r);
	operate_rotate (cal->rra, sta, operate_rr);
	operate_rotate (cal->rrb, stb, operate_rr);
	operate_push (sta, stb, TRUE);
	if (cal->min)
		stb->min = stb->head;
	if (cal->max)
		stb->max = stb->head;
}
