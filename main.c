/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:21:05 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/28 16:57:19 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** check parameter
** add parameter to stack A
*/

#include "push_swap.h"

/*
	// int	nb[] = {1, 2, 3}; // do not operate
	// int	nb[] = {1, 3, 2}; // sa, ra
	// int	nb[] = {3, 2, 1}; // sa, rra
	// int	nb[] = {3, 1, 2}; // ra
	// int	nb[] = {2, 3, 1}; // rra
	// int	nb[] = {2, 1, 3}; // sa
*/
void	solve_three(t_stack *st)
{
	int	n[3];
	n[0] = st->head->n;
	n[1] = st->head->next->n;
	n[2] = st->head->prev->n;
	if (n[0] < n[1] && n[0] < n[2] && n[2] < n[1])
	{
		operate_swap (st);
		operate_r (st);
	}
	else if (n[0] > n[1] && n[1] > n[2] && n[2] < n[1])
	{
		operate_swap (st);
		operate_rr (st);
	}
	else if (n[0] > n[1] && n[1] < n[2] && n[0] > n[2])
		operate_r (st);
	else if (n[0] < n[1] && n[0] > n[2] && n[2] < n[0])
		operate_rr (st);
	else if (n[0] > n[1] && n[1] < n[2] && n[2] > n[0])
		operate_swap (st);
}

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

void	solve(t_stack *sta, t_stack *stb)
{
	while (stb->size < 2 && sta->size > 3)
	{
		operate_push (sta, stb);
	}
	if (stb->size == 2 && stb->head->n < stb->head->next->n){
		PRINT_STACK
		operate_swap (stb);
	}
	PRINT_STACK
	solve_three (sta);
	PRINT_STACK
	size_t i = 0;
	t_lstc	*node = sta->head;
	while (i < sta->size && node->n < stb->head->n)
	{
		i ++;
		node = node->next;
	}
	if (i == 1)
		operate_r (sta);
	else if (i == 2)
		operate_rr (sta);
	PRINT_STACK
	while (stb->size)
	{
		operate_push (stb, sta);
	}
	PRINT_STACK
	while (sta->head->n > sta->head->prev->n)
		operate_rr (sta);
	PRINT_STACK
}

int	main(void)
{
	// int	nb[] = {3, 2, 1, 5, 4, 6};
	int	nb[] = {3, 2, 1, 5, 4};
	// int	nb[] = {3, 2, 1, 5};
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
	solve (sta, stb);

	// PRINT_STACK
	// operate_push (sta, stb);
	// operate_swap (sta);
	// operate_rr (sta);
	// PRINT_STACK
	// operate_push(stb, sta);
	// PRINT_STACK

	return (0);
}