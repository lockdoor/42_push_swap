/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:17:06 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/07 16:51:45 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_lst(t_lstc *lst, size_t size)
{
	while (size--)
	{
		ft_printf("%d\n", lst->n);
		// if (size > 0)
		// 	ft_printf(", ");
		lst = lst->next;
	}
	ft_printf ("\n");
}

void	printf_one_stack (t_stack *st)
{
	printf_lst (st->head, st->size);
	ft_printf ("NAME: %c\n", st->name);
	ft_printf (" MAX: %d\n", st->max->n);
	ft_printf (" MIN: %d\n", st->min->n);
	ft_printf ("SIZE: %d\n", (int) st->size);
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
	ft_printf ("NUM: %4d, cnt: %2d, pb: 1, ra: %2d, rra: %2d, rb: %2d, rrb: %2d, rs %2d, rrs: %2d\n",
		cal->n, (int)cal->cnt, (int)cal->ra, (int)cal->rra, (int)cal->rb, (int)cal->rrb,
		(int)cal->rs, (int)cal->rrs);
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
