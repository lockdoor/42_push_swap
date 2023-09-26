/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:17:06 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/26 13:17:34 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_lst(t_lstc *lst)
{
	t_lstc	*end;

	if (lst == NULL)
		return ;
	end = lst->prev;
	while (lst != end && lst->next != NULL)
	{
		ft_printf("%d, ", lst->n);
		lst = lst->next;
	}
	ft_printf("%d\n", lst->n);
}