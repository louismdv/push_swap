/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:01:34 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/01 18:11:59 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	atob(t_stack **a, t_stack **b)
{
	t_stack	*currentA;
	t_stack	*Atarget;
	t_stack	*tcheapest;
	
	if (check_sort(*a) == false)
	{
		currentA = *a;
		// printf("stackA:\n");
		// printstack(a);
		// printf("stackB:\n");
		// printstack(b);
		// printf("length stackA: %d\n", stack_len(*a));
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
				total_cost(b, stack_len(*a), stack_len(*b));
				tcheapest = cheapest(a);
				// printstack(a);
				// printstack(b);
				// printf(GREEN "Astacklen: %d\n" RESET, stack_len(*a));
				while (currentA != NULL)
				{
					if (currentA->cheapest == true)
					{
						Atarget = currentA->target_node;
						// printf("currentA: %d\n", currentA->value);
						// printf("Atarget: %d\n", Atarget->value);
						bringToTop(a, tcheapest, 'a');
						bringToTop(b, Atarget, 'b');
						// bring_a2top(currentA, a);
						// bring_b2top(Atarget, b);
						ft_pb(a, b);
						// printf(GREEN ">>>>>>>>>> pushing node [%d] to B\n" RESET,
						// currentA->value);
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
