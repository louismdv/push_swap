/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:52:18 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/31 19:15:07 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = NULL;
	a = init_stack(ac, av);
	if (!a)
	{
		printf(RED "error: stack_a is empty\n" RESET);
		return (0);
	}
	if (check_sort(a) == 0)
	{
		if (stack_len(a) == 2)
		{
			// printf("1\n");
			// return 0;
			printf(GREEN"initial stacklen: %d\n"RESET, stack_len(a));
			ft_sa(&a);
		}
		else if (stack_len(a) == 3)
		{
			// printf("2\n");
			// return 0;
			printf(GREEN"initial stacklen: %d\n"RESET, stack_len(a));
			ft_sort3(&a);
			printstack(&a);
		}
		else
		{
			// printf("3\n");
			// return 0;
			printf(GREEN"initial stacklen: %d\n"RESET, stack_len(a));
			if (!b)
				init_b(&a, &b);
			atob(&a, &b);
			btoa(&a,&b);
		}
	}
	ft_free_stack(&a);
}
