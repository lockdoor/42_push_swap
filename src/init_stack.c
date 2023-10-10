/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:50:36 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/10 15:47:02 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* if error in this stage, it free all node and set sta->head to NULL */
static void	add_args_to_stack(t_list *lst, t_stack *sta)
{
	t_lstc	*new;
	int		i;

	i = 0;
	while (lst)
	{
		new = newlstc(*((int *)lst->content));
		lstc_add_back(&(sta->head), new);
		if (sta->head == NULL)
			break ;
		lst = lst->next;
		i++ ;
	}
	sta->size = i;
	if (sta->size > 1)
	{
		sta->max = find_min_max(sta, find_max);
		sta->min = find_min_max(sta, find_min);
	}
}

static void	*copy_content(void *data)
{
	int	*nb;

	nb = (int *) malloc (sizeof(int));
	if (!nb)
		return (NULL);
	*nb = *((int *) data);
	return ((void *) nb);
}

static void	bubble_sort_lst(t_list *lst)
{
	t_list	*head;
	size_t	size;
	void	*content;
	size_t	i;

	size = ft_lstsize(lst);
	while (size)
	{
		head = lst;
		i = size;
		while (i - 1)
		{
			if (*((int *)head->content) > *((int *)head->next->content))
			{
				content = head->content;
				head->content = head->next->content;
				head->next->content = content;
			}
			head = head->next;
			i -- ;
		}
		size -- ;
	}
}

/* copy list and sort list by content */
static t_bool	check_dup(t_list *lst)
{
	t_list	*new;
	t_list	*tmp;
	t_bool	is_dup;

	new = ft_lstmap (lst, &copy_content, &free);
	if (!new)
		return (TRUE);
	bubble_sort_lst (new);
	tmp = new;
	is_dup = FALSE;
	while (tmp->next)
	{
		if (*((int *)tmp->content) == *((int *)tmp->next->content))
		{
			is_dup = TRUE;
			break ;
		}
		tmp = tmp->next;
	}
	ft_lstclear (&new, &free);
	return (is_dup);
}

static void	error_exit(t_stack *sta, t_list **lst)
{
	ft_lstclear (lst, &free);
	ft_printf ("Error\n");
	lstc_clear(&sta->head);
	exit (255);
}

/* require function to add number to stack */
/*
** if not have argument do nothing
** if cannot parse argument print error message
** if duplicate number print error message
** then add argument to stack
*/
void	init_stack(int argc, char **argv, t_stack *sta)
{
	t_list	*lst;

	lst = NULL;
	if (argc < 2)
		return ;
	if (!parse_args (argc, argv, &lst))
	{
		error_exit (sta, &lst);
	}
	if (check_dup (lst))
	{
		error_exit (sta, &lst);
	}
	add_args_to_stack (lst, sta);
	ft_lstclear (&lst, &free);
}
