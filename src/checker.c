/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:22:00 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/10 07:32:57 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* use get_next_line to read fd0 and appand instruction to link list */
static void	make_instruction(t_list **ins)
{
	t_list	*new;
	char	*line;

	while (TRUE)
	{
		line = get_next_line (0);
		if (!line)
			break ;
		new = ft_lstnew (line);
		if (!new)
		{
			free (line);
			ft_lstclear (ins, &free);
			ft_printf ("Error\n");
			break ;
		}
		ft_lstadd_back (ins, new);
	}
}

static t_bool	is_valid_instruction(t_stack *sta, t_stack *stb, char *ins)
{
	if (ft_strncmp(ins, SA, ft_strlen(SA)) == 0)
		operate_swap (sta, FALSE);
	else if (ft_strncmp(ins, SB, ft_strlen(SB)) == 0)
		operate_swap (stb, FALSE);
	else if (ft_strncmp(ins, RA, ft_strlen(RA)) == 0)
		operate_r (sta, FALSE);
	else if (ft_strncmp(ins, RB, ft_strlen(RB)) == 0)
		operate_r (stb, FALSE);
	else if (ft_strncmp(ins, RR, ft_strlen(RR)) == 0)
		operate_rs (sta, stb, FALSE);
	else if (ft_strncmp(ins, RRA, ft_strlen(RRA)) == 0)
		operate_rr (sta, FALSE);
	else if (ft_strncmp(ins, RRB, ft_strlen(RRB)) == 0)
		operate_rr (stb, FALSE);
	else if (ft_strncmp(ins, RRR, ft_strlen(RRR)) == 0)
		operate_rrs (sta, stb, FALSE);
	else if (ft_strncmp(ins, PA, ft_strlen(PA)) == 0)
		operate_push (stb, sta, FALSE);
	else if (ft_strncmp(ins, PB, ft_strlen(PB)) == 0)
		operate_push (sta, stb, FALSE);
	else
		return (FALSE);
	return (TRUE);
}

static void	error_exit(t_stack *sta, t_stack *stb, t_list *ins, char *s)
{
	ft_printf ("%s", s);
	lstc_clear (&sta->head);
	lstc_clear (&stb->head);
	ft_lstclear (&ins, &free);
	exit (0);
}

static void	operate_instruction(t_stack *sta, t_list *ins)
{
	t_stack	stb;
	t_list	*node;
	t_bool	invalid_instruction;

	ft_memset (&stb, 0, sizeof(t_stack));
	node = ins;
	invalid_instruction = FALSE;
	while (node)
	{
		if (!is_valid_instruction(sta, &stb, (char *) node->content))
		{
			invalid_instruction = TRUE;
			break ;
		}
		node = node->next;
	}
	if (invalid_instruction)
		error_exit (sta, &stb, ins, "Error\n");
	if (stb.size != 0)
		error_exit (sta, &stb, ins, "KO\n");
}

/* get argv and parse it to stack if parse error print Error */
/* read fd0 for get instruction if error print Error */
/* use instruction to sort stack */
/* check if sort print OK or KO  */
int	main(int argc, char **argv)
{
	t_list	*instruction;
	t_stack	sta;

	if (argc < 2)
		return (0);
	ft_memset(&sta, 0, sizeof(t_stack));
	sta.name = 'a';
	instruction = NULL;
	make_instruction (&instruction);
	init_stack (argc, argv, &sta);
	if (sta.head)
	{
		operate_instruction (&sta, instruction);
		if (is_sort (&sta))
			ft_printf ("OK\n");
		else
			ft_printf ("KO\n");
		lstc_clear (&sta.head);
		ft_lstclear (&instruction, &free);
	}
	return (0);
}
