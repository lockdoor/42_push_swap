/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:17:06 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/30 14:57:40 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_lst(t_lstc *lst, size_t size)
{
	while (size--)
	{
		ft_printf("%d", lst->n);
		if (size > 0)
			ft_printf(", ");
		lst = lst->next;
	}
	ft_printf ("\n");
}

void	printf_stack(t_lstc *lsta, t_lstc *lstb, size_t a, size_t b)
{
	size_t	r;
	t_lstc	*rest;
	ft_printf ("stack_a\tstack_b\n");
	while (a && b)
	{
		ft_printf ("%d\t%d\n", lsta->n, lstb->n);
		lsta = lsta->next;
		lstb = lstb->next;
		a-- ;
		b-- ;
	}
	if (a)
	{
		rest = lsta;
		r = a;
	}
	else
	{
		rest = lstb;
		r = b;
	}
	while (r--)
	{
		if (b)
			ft_printf ("\t");
		ft_printf ("%d\n", rest->n);
		rest = rest->next;
	}
}

void	print_cal (t_cal *cal)
{
	ft_printf ("NUM: %d, cnt: %d, pb: 1, ra: %d, rra: %d, rb: %d, rrb: %d, rs %d, rrs: %d\n",
		cal->n, (int)cal->cnt, (int)cal->ra, (int)cal->rra, (int)cal->rb, (int)cal->rrb,
		(int)cal->rs, (int)cal->rrs);
}
