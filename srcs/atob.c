/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:01:34 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/05 17:12:35 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	atob(t_stack **a, t_stack **b)
{
	t_stack	*currentA;
	t_stack	*Atarget;
	t_stack	*tcheapest;

	if (check_sort(*a) == false)
	{
		currentA = *a;
		while (stack_len(*a) > 3)
		{
			if (currentA != NULL)
			{
				currentA = *a;
				init_cheap_target(*a);
				init_cheap_target(*b);
				indexing(a);
				indexing(b);
				find_target_nodea(a, b);
				total_cost(a, stack_len(*a), stack_len(*b));
				tcheapest = cheapest(a);
				while (currentA != NULL)
				{
					if (currentA->cheapest == true)
					{
						Atarget = currentA->target_node;
						bringToTop2(a, tcheapest, b, Atarget);
						bringToTop1(a, tcheapest, 'a');
						bringToTop1(b, Atarget, 'b');
						ft_pb(a, b);
						break ;
					}
					currentA = currentA->next;
				}
			}
		}
		if (stack_len(*a) == 3)
			ft_sort3(a);
	}
}
