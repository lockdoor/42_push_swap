/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:19:32 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/27 13:23:07 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lstc	*newlstc(int n)
{
	t_lstc	*new;

	new = (t_lstc *) malloc (sizeof(t_lstc));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->n = n;
	return (new);
}

/*
** free lst until reach end then free the end of lst
** if lst->next == NULL, this lst is only one
*/
void	lstc_clear(t_lstc **lst)
{
	t_lstc	*current;
	t_lstc	*end;
	t_lstc	*tmp;

	current = *lst;
	if (!current)
		return ;
	end = current->prev;
	while (current != end && current->next != NULL)
	{
		tmp = current;
		current = current->next;
		free (tmp);
	}
	free (current);
	*lst = NULL;
}

// should protect if new == NULL, free every thing then return NULL
void	lstc_add_back(t_lstc **lst, t_lstc *new)
{
	t_lstc	*current;

	current = *lst;
	if (new == NULL)
		lstc_clear(lst);
	else if (current == NULL)
		*lst = new;
	else if (current->next == NULL)
	{
		current->next = new;
		current->prev = new;
		new->next = current;
		new->prev = current;
	}
	else
	{
		new->next = current;
		new->prev = current->prev;
		new->prev->next = new;
		current->prev = new;
	}
}

void	init_stack(int *nb, size_t nb_len, t_stack **sta, t_stack **stb)
{
	t_lstc	*lst;
	size_t		i;

	lst = NULL;
	i = nb_len;
	while (i--)
	{
		lstc_add_back(&lst, newlstc(*nb++));
		if (lst == NULL)
			break ;
	}
	if (!lst)
		return ;
	*sta = (t_stack *) ft_calloc (sizeof (t_stack), 1);
	*stb = (t_stack *) ft_calloc (sizeof (t_stack), 1);
	if (!sta || !stb)
		return ;
	(*sta)->head = lst;
	(*sta)->size = nb_len;
	(*sta)->name = 'a';
	(*stb)->name = 'b';
}
