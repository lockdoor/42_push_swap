/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:41:37 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/11 06:45:16 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* help algorithm_b.c to init insruction to 0 */
void	set_zero_rotate(t_cal *tmp)
{
	tmp->ra = 0;
	tmp->rb = 0;
	tmp->rra = 0;
	tmp->rrb = 0;
	tmp->rs = 0;
	tmp->rrs = 0;
}

/* help algorithm_b.c count instruction for set to cnt */
size_t	count_operate(t_cal *c)
{
	return (c->rs + c->rrs + c->ra + c->rb + c->rra + c->rrb + 1);
}

/* help init_stack.c to exit program with error */
void	init_error_exit(t_stack *sta, t_list **lst)
{
	ft_lstclear (lst, &free);
	ft_printf ("Error\n");
	lstc_clear(&sta->head);
	exit (255);
}

/* help parse_args.c to free split */
void	ft_free_split(char **sp)
{
	int	i;

	i = -1;
	while (sp[++i])
	{
		free (sp[i]);
	}
	free (sp);
}
