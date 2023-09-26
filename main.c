/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:21:05 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/26 16:48:23 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** check parameter
** add parameter to stack A
*/

#include "push_swap.h"

/* think about rotation */
// void	scan_stack(t_stack *stack)
// {
// 	t_lstc	*lst;

// 	if (stack->size == 3)
// 	{
// 		lst = stack->head;
// 		while ()
// 	}
// }

int	main(void)
{
	// int	nb[] = {3};
	int	nb[] = {3, 2, 1};
	t_stack	*st_a;
	// t_stack	*stk_b;
	st_a = init_stack(nb, sizeof(nb) / sizeof(int));
	if (!st_a)
	{
		ft_printf (ERR_MESSAGE);
		return (0);
	}
	printf_lst(st_a->head);
	// ft_printf("Hello lockdoor");
	return (0);
}