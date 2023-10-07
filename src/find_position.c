/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:40:06 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/07 15:36:21 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	find_min(int a, int b)
{
	return (a < b);
}

t_bool	find_max(int a, int b)
{
	return (a > b);
}

/* use for set min or max of stack */
t_lstc	*find_min_max(t_stack *st, t_bool (*find)(int, int))
{
	t_lstc	*node;
	t_lstc	*mark;
	size_t	i;

	if (st->size < 3)
		return (NULL);
	// if (st->size == 1)
	// 	return (st->head);
	node = st->head;
	mark = st->head;
	i = 0;
	while (i < st->size)
	{
		if (find (node->n , mark->n))
			mark = node;
		node = node->next;
		i++ ;
	}
	return (mark);
}

/*
t_lstc	*find_by_index(size_t index, t_stack *st)
{
	t_lstc	*node;

	node = st->head;
	while (index--)
		node = node->next;
	return (node);
}
*/


/* use to find min max */
/* it return index of position */
size_t	find_pos(t_stack *st, t_lstc *to_find)
{
	size_t	pos;
	t_lstc	*node;

	pos = 0;
	node = st->head;
	while (node != to_find)
	{
		pos++ ;
		node = node->next;
	}
	return (pos);
}

/* it return index of position */
size_t	find_right_position_stack_b(t_stack *st, int n)
{
	t_lstc	*node;
	size_t	pos;

	node = st->head;
	pos = 0;
	while (TRUE)
	{
		if (n > node->n && n < node->prev->n)
			break ;
		pos ++ ;
		node = node->next;
	}
	return (pos);
}
