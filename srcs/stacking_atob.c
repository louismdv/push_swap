/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking_atob.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:01:34 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/07 00:50:52 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	atob(t_stack **a, t_stack **b)
{
	t_stack	*currenta;

	if (check_sort(*a) == false)
	{
		currenta = *a;
		while (stack_len(*a) > 3)
		{
			if (currenta != NULL)
			{
				currenta = *a;
				init_cheap_target(*a);
				init_cheap_target(*b);
				indexing(a);
				indexing(b);
				find_target_nodea(a, b);
				total_cost(a, stack_len(*a), stack_len(*b));
				atob_suite(currenta, b, a);
			}
		}
		if (stack_len(*a) == 3)
			ft_sort3(a);
	}
}

void	atob_suite(t_stack *currenta, t_stack **b, t_stack **a)
{
	t_stack	*tcheapest;
	t_stack	*atarget;

	tcheapest = cheapest(a);
	while (currenta != NULL)
	{
		if (currenta->cheapest == true)
		{
			atarget = currenta->target_node;
			bringtotop2(a, tcheapest, b, atarget);
			bringtotop1(a, tcheapest, 'a');
			bringtotop1(b, atarget, 'b');
			ft_pb(a, b);
			break ;
		}
		currenta = currenta->next;
	}
}
