/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:40:06 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/30 11:29:51 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
t_bool	find_min(int a, int b)
{
	return (a < b);
}

t_bool	find_max(int a, int b)
{
	return (a > b);
}

void	find_position(t_stack *st, t_bool (*find)(int, int))
{
	t_lstc	*node;
	size_t	i;

	if (st->size == 0)
		return ;
	node = st->head;
	st->mark = node;
	i = 0;
	while (i < st->size)
	{
		if (find (node->n , st->mark->n))
			break ;
		node = node->next;
		i++ ;
	}
	st->mark = node;
	st->mark_pos = i;
}
*/

size_t	find_pos(t_stack *st, t_lstc *to_find)
{
	size_t	pos;
	t_lstc	*node;

	pos = 0;
	node = st->head;
	// if (n == 1)
	// {
	// 	ft_printf ("%d\n", n > node->n);
	// }
	while (node != to_find)
	{
		pos++ ;
		node = node->next;
	}
	return (pos);
}

size_t	find_right_position_stack_b(t_stack *st, int n)
{
	t_lstc	*node;
	size_t	pos;

	node = st->head;
	pos = 0;
	// if (n == 1)
	// {
	// 	ft_printf ("%d\n", n > node->n);
	// }
	while (n < node->n)
	{
		pos ++ ;
		node = node->next;
	}
	return (pos);
}
