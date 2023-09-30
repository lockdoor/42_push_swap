/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:21:05 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/30 16:15:59 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** check parameter
** add parameter to stack A
*/

#include "push_swap.h"
#define	SIZE 20
int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	// int nb[] = {76,79,22,74,70,16,12,54,60,51};
	// int nb[] = {500, 175, 829, 113, 260};
	int nb[SIZE];
	make_numbers_no_dup (nb, SIZE);
 	t_stack	*sta;
	t_stack	*stb;
	sta = NULL;
	stb = NULL;
	init_stack(nb, sizeof(nb) / sizeof(int), &sta, &stb);
	if (!sta || !stb)
	{
		ERR_MESSAGE
		return (0);
	}
	
	PRINT_STACK
	if (is_sort(sta))
	{
		ft_printf ("It is already sort job done!\n");
		return (0);
	}
	// ft_printf ("begin sort\n");
	if (sta->size == 3)
	{
		solve_three (sta);
		PRINT_STACK
		return (0);
	}
	else if (sta->size > 3)
		solve (sta, stb);
	if (!is_sort(sta))
	{
		// ft_printf ("It is already sort job done!\n");
		ft_printf ("Error. It is sort!\n");
		return (0);
	}
	return (0);
}