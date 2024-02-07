/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:52:18 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/07 00:51:34 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
			ft_sa(&a);
		else if (stack_len(a) == 3)
			ft_sort3(&a);
		else
		{
			if (!b)
				init_b(&a, &b);
			atob(&a, &b);
			btoa(&a, &b);
			bringtotop1(&a, ft_find_min(a), 'a');
		}
	}
	ft_free_stack(&a);
}
