/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:08:56 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/08 14:08:19 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	ft_atoi2(const char *str, int *dst)
{
	unsigned long	n;
	int				sign;

	n = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++ ;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++ ;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (FALSE);
		n = (n * 10) + (*str - '0');
		if ((sign == -1 && n - 1 > INT_MAX) || (sign == 1 && n > INT_MAX))
			return (FALSE);
		str++ ;
	}
	*dst = n * sign;
	return (TRUE);
}

static void	ft_free_split(char **sp)
{
	int	i;

	i = -1;
	while (sp[++i])
	{
		free (sp[i]);
	}
	free (sp);
}

static t_bool	handle_parse_int_error(t_list **lst)
{
	ft_lstclear (lst, &free);
	return (FALSE);
}

static t_bool	parse_int(char **numbers, t_list **lst)
{
	int		i;
	int		nb;
	int		*n;
	t_list	*new;

	i = -1;
	while (numbers[++i])
	{
		if (!ft_atoi2(numbers[i], &nb))
			return (handle_parse_int_error (lst));
		n = (int *) malloc (sizeof(int));
		if (!n)
			return (handle_parse_int_error (lst));
		*n = nb;
		new = ft_lstnew(n);
		if (!new)
			return (handle_parse_int_error (lst));
		ft_lstadd_back(lst, new);
	}
	return (TRUE);
}

t_bool	parse_args(int argc, char **argv, t_list **lst)
{
	int		i;
	char	**numbers;

	i = 0;
	while (++i < argc)
	{
		numbers = ft_split(argv[i], 32);
		if (!numbers)
		{
			ERR_MESSAGE
			return (FALSE);
		}
		if (!parse_int (numbers, lst))
		{
			ft_free_split (numbers);
			return (FALSE);
		}
		ft_free_split (numbers);
	}
	return (TRUE);
}
