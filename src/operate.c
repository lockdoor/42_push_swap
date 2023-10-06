/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 06:59:44 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/28 16:39:02 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swap group */
static void	swap(t_stack *st)
{
	t_lstc	*head;
	t_lstc	*second;

	head = st->head;
	if (!head)
		return ;
	second = head->next;
	if (!second)
		return ;
	if (second->next != head)
	{
		head->prev->next = second;
		second->next->prev = head;

		second->prev = head->prev;
		head->prev = second;
		
		head->next = second->next;
		second->next = head;
	}
	st->head = second;
}

void	operate_swap(t_stack *st)
{
	swap(st);
	ft_printf("s%c\n", st->name);
}

void	operate_ss(t_stack *sta, t_stack *stb)
{
	swap(sta);
	swap(stb);
	ft_printf("ss\n");
}

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
	ft_printf("rs\n");
}

/* reverse_rotate group */
static void	reverse_rotate(t_stack *st)
{
	if (st->head->prev)
		st->head = st->head->prev;
}

void	operate_rr(t_stack *st)
{
	reverse_rotate (st);
	ft_printf("rr%c\n", st->name);
}

void	operate_rrs(t_stack *sta, t_stack *stb)
{
	reverse_rotate (sta);
	reverse_rotate (stb);
	ft_printf("rrs\n");
}

/* push group */
void	operate_push(t_stack *from, t_stack *to)
{
	t_lstc	*f;
	t_lstc	*t;

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
		// t->prev->next->next = f;
		t->prev = f;
	}
	to->head = f;
	to->size +=1;
	ft_printf ("p%c\n", to->name);
}
