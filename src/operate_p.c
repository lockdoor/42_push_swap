/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 06:59:44 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/11 07:16:37 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	operate_push_h(t_lstc *f, t_stack *to, t_bool print)
{
	t_lstc	*t;

	t = to->head;
	if (t == NULL)
		t = f;
	else if (t->next == NULL)
	{
		t->prev = f;
		t->next = f;
		f->prev = t;
		f->next = t;
	}
	else
	{
		f->prev = t->prev;
		f->next = t;
		t->prev->next = f;
		t->prev = f;
	}
	to->head = f;
	to->size += 1;
	if (print)
		ft_printf ("p%c\n", to->name);
}

/* push group */
void	operate_push(t_stack *from, t_stack *to, t_bool print)
{
	t_lstc	*f;

	if (from->size == 0 || from->head == NULL)
		return ;
	f = from->head;
	from->size -= 1;
	if (from->size == 0)
		from->head = NULL;
	else if (from->size == 1)
	{
		f->prev->next = NULL;
		f->next->next = NULL;
		from->head = f->next;
	}
	else
	{
		f->prev->next = f->next;
		f->next->prev = f->prev;
		from->head = f->next;
	}
	f->next = NULL;
	f->prev = NULL;
	operate_push_h(f, to, print);
}
