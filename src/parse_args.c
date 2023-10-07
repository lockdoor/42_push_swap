/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:08:56 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/07 12:04:42 by pnamnil          ###   ########.fr       */
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
	if (!ft_isdigit(*str))
		return (FALSE);
	while (ft_isdigit(*str))
	{
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

static t_bool	parse_int(char **numbers, int *idx, int *nb)
{
	int	i;

	i = -1;
	while (numbers[++i])
	{
		if (!ft_atoi2(numbers[i], &nb[*idx]))
		{
			ft_printf ("Error: Some arguments are not integers!\n");
			return (FALSE);
		}
		*idx += 1 ;
		if (*idx >= BUF_SIZE)
		{
			// ft_printf ("idx max: %d\n", *idx);
			// exit (1);
			break ;
		}
	}
	return (TRUE);
}

t_bool	parse_args(int argc, char **argv, int *idx, int *nb)
{
	int		i;
	char	**numbers;

	i = 0;
	while (++i < argc)
	{
		numbers = ft_split(argv[i], 32);
		if (!numbers)
		{
			ft_printf ("Error: Can not init argument!\n");
			return (FALSE);
		}
		if (!parse_int (numbers, idx, nb))
		{
			ft_free_split (numbers);
			return (FALSE);
		}
		ft_free_split (numbers);
		if (*idx >= BUF_SIZE)
			break ;
	}
	return (TRUE);
}
