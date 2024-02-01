/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:52:18 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/01 18:39:45 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = init_stack(ac, av);
	if (!a)
		return (0);
	if (check_sort(a) == false)
	{
		if (stack_len(a) == 2)
		{
			// printf(GREEN "initial stacklen: %d\n" RESET, stack_len(a));
			ft_sa(&a);
		}
		else if (stack_len(a) == 3)
		{
			// printf(GREEN "initial stacklen: %d\n" RESET, stack_len(a));
			ft_sort3(&a);
			// printstack(&a);
		}
		else
		{
			// printf(GREEN "initial stacklen: %d\n" RESET, stack_len(a));
			if (!b)
				init_b(&a, &b);
			atob(&a, &b);
			/* 	if (stack_len(a) == 3)
				{
					printstack(&b);
					printf("------------------------------\n");
					printstack(&a);
				} */
			btoa(&a, &b);
			/* printstack(&a); */
			bringToTop(&a, ft_find_min(a), 'a');
		}
	}
	ft_free_stack(&a);
}
