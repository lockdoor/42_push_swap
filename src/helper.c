/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:41:37 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/10 10:26:28 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* help algorithm_b.c to init insruction to 0 */
void	set_zero_rotate(t_cal *tmp)
{
	tmp->ra = 0;
	tmp->rb = 0;
	tmp->rra = 0;
	tmp->rrb = 0;
	tmp->rs = 0;
	tmp->rrs = 0;
}

/* help algorithm_b.c count instruction for set to cnt */
size_t	count_operate(t_cal *c)
{
	return (c->rs + c->rrs + c->ra + c->rb + c->rra + c->rrb + 1);
}
