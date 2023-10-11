/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:08:56 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/11 07:13:36 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_atoi2_h(const char *str, int *sign)
{
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++ ;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign *= -1;
		str++ ;
	}
	return ((char *) str);
}

static t_bool	ft_atoi2(const char *str, int *dst)
{
	unsigned long	n;
	int				sign;

	n = 0;
	sign = 1;
	str = ft_atoi2_h (str, &sign);
	if (!ft_isdigit(*str))
		return (FALSE);
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

/* 
** parse argument
** first split each argument to string array
** second parse int each string in array by ft_atoi2
*/
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
			ft_printf ("Error\n");
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

/* parse_args with debug mode
t_bool	parse_args(int argc, char **argv, t_list **lst)
{
	int		i;
	char	**numbers;

	i = 0;
	while (++i < argc)
	{
		if (DEBUG_MODE)
			ft_printf ("%s\n", argv[i]);
		numbers = ft_split(argv[i], 32);
		if (!numbers)
		{
			ft_printf ("Error\n");
			return (FALSE);
		}
		if (!parse_int (numbers, lst))
		{
			ft_free_split (numbers);
			return (FALSE);
		}
		if (DEBUG_MODE)
			printSprit (numbers);
		ft_free_split (numbers);
	}
	return (TRUE);
}
*/