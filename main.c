/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:52:18 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/30 23:43:00 by louismdv         ###   ########.fr       */
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
	if (!check_sort(a))
	{
		if (stack_len(a) == 2)
			ft_sa(&a);
		else if (stack_len(a) == 3)
			ft_sort3(&a);
		if (!b)
			init_b(&a, &b);
		atob(&a, &b);
	}
	btoa(&a,&b);
	ft_free_stack(&a);
}
