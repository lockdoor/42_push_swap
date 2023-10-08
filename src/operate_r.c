/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:06:30 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/08 16:07:05 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rotate group */
static void	rotate(t_stack *st)
{
	if (st->head->next)
		st->head = st->head->next;
}

void	operate_r(t_stack *st)
{
	rotate (st);
	ft_printf("r%c\n", st->name);
}

void	operate_rs(t_stack *sta, t_stack *stb)
{
	rotate (sta);
	rotate (stb);
	ft_printf("rr\n");
}
