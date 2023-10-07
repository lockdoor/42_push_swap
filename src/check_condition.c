/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:41:49 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/07 14:34:36 by pnamnil          ###   ########.fr       */
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

static void	ft_bubble_sort(int *nb, int len)
{
	int	i;
	int	tmp;

	while (len - 1 > 0)
	{
		i = 0;
		while (i < len - 1)
		{
			if (nb[i] > nb[i+1])
			{
				tmp = nb[i];
				nb[i] = nb[i+1];
				nb[i+1] = tmp;
			}
			i++ ;
		}
		len-- ;
	}
}

t_bool	ft_is_dup(int *nb, int len)
{
	int *n;
	int i;

	n = malloc (sizeof(int) * len);
	ft_memcpy(n, nb, sizeof(int) * len);
	ft_bubble_sort (n, len);
	i = -1;
	while (++i < len - 1)
	{
		if (n[i] == n[i + 1])
		{
			return (TRUE);
		}
	}
	free (n);
	return (FALSE);
}
