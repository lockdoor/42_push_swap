/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:07:31 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/11 07:15:08 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* reverse_rotate group */
static void	reverse_rotate(t_stack *st)
{
	if (st->size >= 2)
		st->head = st->head->prev;
}

void	operate_rr(t_stack *st, t_bool print)
{
	reverse_rotate (st);
	if (print)
		ft_printf("rr%c\n", st->name);
}

void	operate_rrs(t_stack *sta, t_stack *stb, t_bool print)
{
	reverse_rotate (sta);
	reverse_rotate (stb);
	if (print)
		ft_printf("rrr\n");
}
