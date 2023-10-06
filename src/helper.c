/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:41:37 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/06 09:41:53 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_zero_rotate(t_cal *tmp)
{
	tmp->ra = 0;
	tmp->rb = 0;
	tmp->rra = 0;
	tmp->rrb = 0;
	tmp->rs = 0;
	tmp->rrs = 0;
}

size_t count_operate(t_cal *c)
{
	return (c->rs + c->rrs + c->ra + c->rb + c->rra + c->rrb + 1);
}
