/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:21:46 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/02 11:08:29 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operate_rotate (size_t cnt, t_stack *st, void(*operate)(t_stack *))
{
	while (cnt)
	{
		operate (st);
		cnt-- ;
	}
}

void	operate_rotate_db (size_t cnt, t_stack *sta, t_stack *stb,
	void(*operate)(t_stack *, t_stack *))
{
	while (cnt)
	{
		operate (sta, stb);
		cnt-- ;
	}
}

void	operate_by_cheep(t_cal *cal, t_stack *sta, t_stack *stb)
{
	operate_rotate_db (cal->rs, sta, stb, operate_rs);
	operate_rotate_db (cal->rrs, sta, stb, operate_rrs);
	operate_rotate (cal->ra, sta, operate_r);
	operate_rotate (cal->rb, stb, operate_r);
	operate_rotate (cal->rra, sta, operate_rr);
	operate_rotate (cal->rrb, stb, operate_rr);
	operate_push (sta, stb);
	if (cal->min)
	{
		stb->min = stb->head;
		// operate_r (stb);
	}
	if (cal->max)
		stb->max = stb->head;
}

void	push_b(t_stack *sta, t_stack *stb)
{
	t_cal	cheep;
	t_cal	candidate;
	size_t	i; // for count rotate sta
	size_t	j; // for count rotate stb
	t_lstc	*node_a;
	
	// while (sta->size > 3)
	while (sta->size > 3 && !lstc_is_sort(sta))
	{
		init_cal (&cheep);
		cheep.cnt = INT_MAX;
		i = 0;
		node_a = sta->head;
		/* loop every node for count operation */
		while (i < sta->size)
		{
			init_cal (&candidate);
			candidate.n = node_a->n;
			// candidate.cnt = i + 1; //plus 1 because default operation is push
			candidate.ra = i;
			if (i > sta->size / 2)
			{
				// candidate.cnt = sta->size - i + 1;
				candidate.ra = 0;
				candidate.rra = sta->size - i;
			}
			/* new min or max in stack B, retate max on stack B to top then push B */
			if (node_a->n > stb->max->n || node_a->n < stb->min->n)
			{
				j = find_pos(stb, stb->max);
				if (node_a->n > stb->max->n)
				{
					// ft_printf ("This is new max, NUM: %d, j: %d\n", node_a->n, (int)j);
					candidate.max = TRUE;
				}
				else
				{
					// ft_printf ("This is new min, NUM: %d, j: %d\n", node_a->n, (int)j);
					candidate.min = TRUE;
				}
			}
			else
			{
				/* get position in stack */
				j = find_right_position_stack_b(stb, node_a->n);
				// ft_printf ("NUM: %d, j: %d\n", node_a->n, (int)j);
			}
			candidate.rb = j;
			if (j > stb->size / 2)
			{
				candidate.rb = 0;
				candidate.rrb = stb->size - j;
			}
			cnt_candidate(&candidate);

			/* debug */
			// print_cal (&candidate);
			
			set_cheep (&cheep, &candidate);
			node_a = node_a->next;
			i++ ;
		}
		/* debug */
		// ft_printf ("winner is: \n");
		// print_cal (&cheep);
		
		operate_by_cheep (&cheep, sta, stb);
		PRINT_STACK
	}
}
