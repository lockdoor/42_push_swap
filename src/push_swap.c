/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:40:44 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/07 09:26:37 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* parse argument to stack_a */
/* if stack_a->head sent stack_a to sort function */
int	main(int argc, char **argv)
{
	t_stack	sta;

	ft_memset(&sta, 0, sizeof(t_stack));
	sta.name = 'a';
	init_stack (argc, argv, &sta);
	if (sta.head)
	{
		sort_stack (&sta);
		if (DEBUG_MODE)
		{
			if (!is_sort(&sta))
			{
				ft_printf ("Error: on main sta is not sort!\n");
				exit (1);
			}
			printf_one_stack (&sta);
		}
		lstc_clear(&sta.head);
	}
	return (0);
}