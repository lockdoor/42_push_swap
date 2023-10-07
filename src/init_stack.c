/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:50:36 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/06 15:22:11 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* if error in this stage, it free all node and set sta->head to NULL */
void	add_args_to_stack(int argc, int *nb, t_stack *sta)
{
	t_lstc	*new;
	int		i;

	i = -1;
	while (++i < argc)
	{
		new = newlstc(nb[i]);
		lstc_add_back(&(sta->head), new);
		if (sta->head == NULL)
			break ;
	}
	sta->size = i;
	sta->max = find_min_max(sta, find_max);
	sta->min = find_min_max(sta, find_min);
}


/* require function to parse argv */
// if parse failed return NULL and print "parse faild"
// if duplicate number return NULL and print "number duplicate"
// if sorted return NULL and print "is sorted"
/* require function to add number to stack */
/* debug */
// for (int i = 0; i < idx; i++)
// 	ft_printf ("%d, ", nb[i]);
// ft_printf ("\n");
void	init_stack(int argc, char **argv, t_stack *sta)
{
	int		nb[BUF_SIZE];
	int		idx;

	if (argc < 2)
		return ;
	idx = 0;
	if (!parse_args (argc, argv, &idx, nb))
		return ;
	add_args_to_stack (idx, nb, sta);
}
