/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:41:49 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/09 16:30:03 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_sort(t_stack *st)
{
	t_lstc	*node;
	size_t	size;

	node = st->head;
	size = st->size;
	if (size == 1 || node == NULL)
		return (TRUE);
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
t_bool	lstcb_is_sort(t_stack *st)
{
	t_lstc	*node;
	t_lstc	*max;

	max = find_min_max (st, find_max);
	node = max;
	while (node->next != max)
	{
		if (node->n < node->next->n)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}

t_bool	lstca_is_sort(t_stack *st)
{
	t_lstc	*node;
	t_lstc	*min;

	min = find_min_max (st, find_min);
	node = min;
	while (node->next != min)
	{
		if (node->n > node->next->n)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}
