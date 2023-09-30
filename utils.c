/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:57:25 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/30 15:50:29 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "libft/includes/ft_printf.h"
#include <time.h>  
// #include <stdlib.h>

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

// #define SIZE 10
// int main(void)
// {
//     int nb[SIZE];
//     size_t  i;

//     make_numbers_no_dup (nb, SIZE);
//     i = 0;
//     while (i < SIZE)
//     {
//         ft_printf ("%d", nb[i]);
//         if (i < SIZE - 1)
//             ft_printf (", ");
//         else
//             ft_printf ("\n");
//         i++ ;
//     } 
// }
