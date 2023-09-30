/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:28:44 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/30 11:18:28 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_cal (t_cal *cal)
{
	cal->cnt = 0;
	cal->push = 1;
	cal->ra = 0;
	cal->rb = 0;
	cal->rra = 0;
	cal->rrb = 0;
	cal->rs = 0;
	cal->rrs = 0;
	cal->min = FALSE;
	cal->max = FALSE;
}

/* count and calculate rs or rrs */
void	cnt_candidate (t_cal *cdd)
{
	cdd->cnt = 0;
	while (cdd->ra && cdd->rb)
	{
		cdd->ra -= 1;
		cdd->rb -= 1;
		cdd->rs += 1;
	}
	while (cdd->rra && cdd->rrb)
	{
		cdd->rra -= 1;
		cdd->rrb -= 1;
		cdd->rrs += 1;
	}
	cdd->cnt += cdd->push;
	cdd->cnt += cdd->ra;
	cdd->cnt += cdd->rb;
	cdd->cnt += cdd->rra;
	cdd->cnt += cdd->rrb;
	cdd->cnt += cdd->rs;
	cdd->cnt += cdd->rrs;
}

void	set_cheep (t_cal *cheep, t_cal *candidate)
{
	if (candidate->cnt < cheep->cnt)
	{
		cheep->n = candidate->n;
		cheep->cnt = candidate->cnt;
		cheep->ra = candidate->ra;
		cheep->rb = candidate->rb;
		cheep->rra = candidate->rra;
		cheep->rrb = candidate->rrb;
		cheep->rs = candidate->rs;
		cheep->rrs = candidate->rrs;
		cheep->min = candidate->min;
		cheep->max = candidate->max;
	}
}
