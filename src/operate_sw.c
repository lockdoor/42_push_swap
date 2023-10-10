/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_sw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:02:56 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/10 10:08:11 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swap group */
/*
** make sure head not NULL and stack size more then and equal 2
** if stack is equal 2 just chage stack head
*/
static void	swap(t_stack *st)
{
	t_lstc	*head;
	t_lstc	*second;

	head = st->head;
	if (!head && head->next)
		return ;
	second = head->next;
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

void	operate_swap(t_stack *st, t_bool print)
{
	swap(st);
	if (print)
		ft_printf("s%c\n", st->name);
}

void	operate_ss(t_stack *sta, t_stack *stb, t_bool print)
{
	swap(sta);
	swap(stb);
	if (print)
		ft_printf("ss\n");
}
