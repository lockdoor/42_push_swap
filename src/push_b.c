/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:26:50 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/10 10:38:40 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* calculate each algorithm to find best choise */
static void	find_best_algolithm(t_cal *cdd)
{
	t_cal	tmp;
	void	(*func[5])(t_cal *);
	int		i;

	ft_memcpy (&tmp, cdd, sizeof(t_cal));
	func[0] = &rs;
	func[1] = &rrs;
	func[2] = &rotate_min;
	func[3] = &rarrb;
	func[4] = &rrarb;
	i = -1;
	while (++i < 5)
	{
		func[i](&tmp);
		if (cdd->cnt > tmp.cnt)
			ft_memcpy (cdd, &tmp, sizeof(t_cal));
	}
}

static void	setup_candidate(t_cal *cdd, int cn, t_stack *sta, t_stack *stb)
{
	ft_memset (cdd, 0, sizeof(t_cal));
	cdd->cnt = INT_MAX;
	cdd->n = cn;
	cdd->len_a = sta->size;
	cdd->len_b = stb->size;
	if (cdd->n < stb->min->n || cdd->n > stb->max->n)
	{
		cdd->idx_b = find_pos(stb, stb->max);
		if (cdd->n < stb->min->n)
			cdd->min = TRUE;
		else
			cdd->max = TRUE;
	}
	else
		cdd->idx_b = find_right_position_stack_b (stb, cdd->n);
}

/* calculate each algorithm to find best choise */
static void	find_best_cdd(t_cal *champ, t_stack *sta, t_stack *stb)
{
	t_cal	cdd;
	t_lstc	*lstc_a;
	size_t	index;

	index = 0;
	lstc_a = sta->head;
	while (index < sta->size)
	{
		setup_candidate (&cdd, lstc_a->n, sta, stb);
		cdd.idx_a = index;
		find_best_algolithm(&cdd);
		if (champ->cnt > cdd.cnt)
			ft_memcpy (champ, &cdd, sizeof(t_cal));
		index ++ ;
		lstc_a = lstc_a->next;
	}
}

/* with debug mode find_best_cdd */
/*
void	find_best_cdd(t_cal *champ, t_stack *sta, t_stack *stb)
{
	t_cal	cdd;
	t_lstc	*lstc_a;
	size_t	index;

	index = 0;
	lstc_a = sta->head;
	while (index < sta->size)
	{
		setup_candidate (&cdd, lstc_a->n, sta, stb);
		cdd.idx_a = index;

		find_best_algolithm(&cdd);
		
if (DEBUG_MODE)
{			
	print_cal (&cdd);
	if (cdd.min || cdd.max)
	{
		ft_printf ("min: %d, max: %d, a_len: %d, a_idx: %d, b_len: %d, b_idx: %d\n",
			cdd.min, cdd.max,
			(int) cdd.len_a, (int) cdd.idx_a,
			(int) cdd.len_b, (int) cdd.idx_b);
	}
}
		
		if (champ->cnt > cdd.cnt)
			ft_memcpy (champ, &cdd, sizeof(t_cal));
		index ++ ;
		lstc_a = lstc_a->next;
	}
}
*/

/* calculate each number of sta, find champ is spend less times */
void	push_b_until(t_stack *sta, t_stack *stb)
{
	t_cal	champ;

	stb->min = find_min_max (stb, find_min);
	stb->max = find_min_max (stb, find_max);
	while (sta->size > 3 && !lstca_is_sort(sta))
	{
		ft_memset (&champ, 0, sizeof(t_cal));
		champ.cnt = INT_MAX;
		find_best_cdd (&champ, sta, stb);
		operate_by_champ (&champ, sta, stb);
	}
}

/* with debug mode push_b_until */
/*
void	push_b_until(t_stack *sta, t_stack *stb)
{
	t_cal	champ;
	
	stb->min = find_min_max (stb, find_min);
	stb->max = find_min_max (stb, find_max);
	if (DEBUG_MODE)
	{
		PRINT_STACK
		ft_printf ("min_b: %d\n", stb->min->n);
		printf_one_stack(sta);	
		printf_one_stack(stb);
	}
	while (sta->size > 3 && !lstca_is_sort(sta))
	{
		ft_memset (&champ, 0, sizeof(t_cal));
		champ.cnt = INT_MAX;
		find_best_cdd (&champ, sta, stb);
		
		// push champ normally
		operate_by_champ (&champ, sta, stb);
		
		if (DEBUG_MODE)
		{
			PRINT_STACK
			if (!lstcb_is_sort(stb))
			{
				printf_stack (sta->head, stb->head, sta->size, stb->size);
				ft_printf ("max: %d\n", stb->max->n);
				ft_printf ("Error stack_B not sort");
				exit (0);
			}	
		}
	}
}
*/
