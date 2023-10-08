/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_sw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:02:56 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/08 16:05:38 by pnamnil          ###   ########.fr       */
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
