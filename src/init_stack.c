/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:50:36 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/06 09:23:50 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_args_to_stack(int argc, char **argv, t_stack *sta)
{
	t_lstc	*new;
	int		i;

	i = 0;
	while (++i < argc)
	{
		new = newlstc(ft_atoi(argv[i]));
		lstc_add_back(&(sta->head), new);
		if (sta->head == NULL)
			break;
	}
	sta->size = i - 1;
	sta->max = find_min_max(sta, find_max);
	sta->min = find_min_max(sta, find_min);
}

void	init_stack(int argc, char **argv, t_stack *sta)
{
    /* require function to parse argv */
    // if parse failed return NULL and print "parse faild"
    // if duplicate number return NULL and print "number duplicate"
    // if sorted return NULL and print "is sorted"

    /* require function to add number to stack */
	return add_args_to_stack (argc, argv, sta);
}
