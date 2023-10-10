/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:06:30 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/10 09:57:06 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rotate group */
static void	rotate(t_stack *st)
{
	if (st->head && st->head->next)
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
