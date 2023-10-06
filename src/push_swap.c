/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:40:44 by pnamnil           #+#    #+#             */
/*   Updated: 2023/10/06 11:32:18 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>
#define	SIZE 501

static t_bool  is_dup (int *nb, size_t size, int n)
{
    size_t  i;

    i = 0;
    while (i < size)
    {
        if (nb[i] == n)
            return (TRUE);
        i++ ;
    }
    return (FALSE);
}

void make_numbers_no_dup (int *nb, size_t size)
{
	time_t	t;
	size_t	i;
    int     rd;

	i = 0;
	srand ((unsigned) time(&t));  
	while (i < size)
	{
        while (TRUE)
        {
            rd = rand() % 1000;
            if (!is_dup(nb, i, rd))
                break ;
        }
		nb[i] = rd;
        i++ ;
	}
}

int	main(int argc, char **argv)
{
	int		nb[SIZE];
	char	*number[SIZE];
 	t_stack	sta;
	int		i;
	
	(void) argc;
	(void) argv;
	make_numbers_no_dup (nb, SIZE);
	
	i = -1;
	while (++i < SIZE)
		number[i] = ft_itoa(nb[i]);
		i++ ;
		
	// i = -1;
	// while (++i < SIZE)
	// 	ft_printf ("%s\n", number[i]);
		
	// int nb[] = {76,79,22,74,70,16,12,54,60,51};

	/* parse argument to stack_a */
	// funtion to parse argument return stack_a or NULL
	// if return NULL should print errer message
	ft_memset(&sta, 0, sizeof(t_stack));
	sta.name = 'a';
	init_stack (SIZE, number, &sta);
	
	i = -1;
	while (++i < SIZE)
		free (number[i]);
	
	/* if stack_a sent stack_a to sort function */
	if (sta.head)
	{
		// ft_printf ("stack created\n");
		// printf_one_stack (&sta);
		sort_stack (&sta);
	}
	if (!is_sort(&sta))
	{
		ft_printf ("Error: on main sta is not sort!\n");
		printf_one_stack (&sta);
		exit (1);
	}
	lstc_clear(&sta.head);
	return (0);
}