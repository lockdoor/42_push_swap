/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:06:30 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/11 07:14:56 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rotate group */
static void	rotate(t_stack *st)
{
	if (st->size >= 2)
		st->head = st->head->next;
}

void	operate_r(t_stack *st, t_bool print)
{
	rotate (st);
	if (print)
		ft_printf("r%c\n", st->name);
}

void	operate_rs(t_stack *sta, t_stack *stb, t_bool print)
{
	rotate (sta);
	rotate (stb);
	if (print)
		ft_printf("rr\n");
}
