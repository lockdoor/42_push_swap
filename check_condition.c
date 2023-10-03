/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:41:49 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/02 11:27:50 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_bool	is_sort(t_stack *st)
{
	t_lstc	*node;
	size_t	size;

	node = st->head;
	size = st->size;
	while (size--)
	{
		if (node->n > node->next->n)
			break ;
		node = node->next;
	}
	if (node == st->head->prev)
		return (TRUE);
	return (FALSE);
}

/* this function is check sort */
t_bool	lstc_is_sort(t_stack *st)
{
	t_lstc	*node;
	size_t	size;

	find_position (st, find_min);
	node = st->mark;
	size = st->size;
	while (size--)
	{
		if (node->n > node->next->n)
			break ;
		node = node->next;
	}
	if (node == st->mark->prev)
	{
		ft_printf ("sta is sort!\n");
		return (TRUE);
	}
	return (FALSE);
}
