/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:17:06 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/08 15:50:54 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_lst(t_lstc *lst, size_t size)
{
	while (size--)
	{
		ft_printf("%d\n", lst->n);
		lst = lst->next;
	}
	ft_printf ("\n");
}

void	printf_one_stack(t_stack *st)
{
	printf_lst (st->head, st->size);
	if (st->name)
		ft_printf ("NAME: %c\n", st->name);
	if (st->max)
		ft_printf (" MAX: %d\n", st->max->n);
	if (st->min)
		ft_printf (" MIN: %d\n", st->min->n);
	if (st->size)
		ft_printf ("SIZE: %d\n", (int) st->size);
}

static	t_lstc	*set_rest(size_t a, t_lstc *lsta, t_lstc *lstb)
{
	if (a)
		return (lsta);
	else
		return (lstb);
}

void	printf_stack(t_lstc *lsta, t_lstc *lstb, size_t a, size_t b)
{
	size_t	r;
	t_lstc	*rest;

	ft_printf ("stack_a\tstack_b\n");
	while (a-- && b--)
	{
		ft_printf ("%d\t%d\n", lsta->n, lstb->n);
		lsta = lsta->next;
		lstb = lstb->next;
	}
	rest = set_rest (a, lsta, lstb);
	if (a)
		r = a;
	else
		r = b;
	while (r--)
	{
		if (b)
			ft_printf ("\t");
		ft_printf ("%d\n", rest->n);
		rest = rest->next;
	}
}

void	print_cal(t_cal *cal)
{
	ft_printf ("NUM: %4d, cnt: %2d, pb: 1, ra: %2d, rra: %2d,\
		rb: %2d, rrb: %2d, rs %2d, rrs: %2d\n",
		cal->n, (int)cal->cnt, (int)cal->ra, (int)cal->rra,
		(int)cal->rb, (int)cal->rrb, (int)cal->rs, (int)cal->rrs);
}

/*
void	printArray(int *nb, int len)
{
	while (len--)
	{
		ft_printf("%d", *nb);
		if(len > 0)
			ft_printf(", ");
		nb++ ;
	}
	ft_printf("\n");
}

void	printSprit(char **nb)
{
	while (*nb)
	{
		ft_printf("%s ", *nb);
		nb++ ;
	}
	ft_printf("\n");
}
*/
