/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:52:18 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/26 01:17:49 by louismdv         ###   ########.fr       */
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
		printf("stack_a is empty\n");
		return (0);
	}
	if (check_sort(a) == 0)
	{
		if (stack_len(a) == 2)
			ft_sa(&a);
		else if (stack_len(a) == 3)
			ft_sort3(&a);
		else if(b == NULL)
			init_b(&a, &b);
		ft_sort(&a, &b);
	}
	if (b == NULL)
		printf("stack_b is empty\n");

	//print push cost + undermedian flag for each node in stackA
	//print push cost + undermedian flag for each node in stackB
	//print total push cost for each node in stackA
	//print cheapest for each node in stackA
	ft_free_stack(&a);
}
