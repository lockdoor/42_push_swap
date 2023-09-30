/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:43:28 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/30 15:49:29 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	st->min = st->head;
	st->max = st->head->prev;
}

void	rotate_max_pos(t_stack *st)
{
	size_t	pos;
	
	pos = find_pos(st, st->max);
	if (pos == 0)
		return ;
	if (pos < st->size / 2)
	{
		pos = st->size - pos;
		operate_rotate (pos, st, operate_rr);
	}
	else
	{
		operate_rotate (pos, st, operate_r);
	}
}



/* push B with out calculate until stb->size == 2*/
/* swab stack B for correct position head must more then second */
/* push rest of stack A to B */
/* make sure the stack is sort and set min | max of stack*/
/* rotate stb make sure the top of stack is max */
/* check sta rotate to right posision before push */
void	solve(t_stack *sta, t_stack *stb)
{
	while (stb->size < 2 && sta->size > 3)
		operate_push (sta, stb);
	PRINT_STACK
	
	if (stb->head->n < stb->head->next->n)
	{
		operate_swap (stb);
	}
	stb->max = stb->head;
	stb->min = stb->head->next;
	PRINT_STACK
	// ft_printf ("pass this\n");
	push_b (sta, stb);
	PRINT_STACK

	solve_three (sta);
	PRINT_STACK

	rotate_max_pos (stb);
	PRINT_STACK
	
	push_a (sta, stb);
	PRINT_STACK
}
