/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:01:34 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/31 19:09:25 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	atob(t_stack **a, t_stack **b)
{
	t_stack *currentA;
	t_stack *Atarget;

	printf(RED "[AtoB: ...]\n" RESET);
	if (check_sort(*a) == 0)
	{
		currentA = *a;
		printstack(a);
		printf("length stackA: %d\n", stack_len(*a));
		while (stack_len(*a) > 3)
		{
			if (currentA != NULL)
			{			
				currentA = *a;
				init_cheapest(*a);
				init_cheapest(*b);
				indexing(a);
				indexing(b);
				find_target_nodea(a, b);
				total_cost(a, stack_len(*a), stack_len(*b));
				total_cost(b, stack_len(*a), stack_len(*b));
				cheapest(a);
				cheapest(b);
				printf(GREEN"Astacklen: %d\n"RESET, stack_len(*a));
				while (currentA != NULL)
				{
					if (currentA->cheapest == 1)
					{
						Atarget = currentA->target_node;
						printf("currentA: %d\n", currentA->value);
						printf("Atarget: %d\n", Atarget->value);
						bring_a2top(currentA, a);
						bring_b2top(Atarget, b);
						ft_pb(a, b);
						printf(GREEN ">>>>>>>>>> pushing node [%d] to B\n" RESET, currentA->value);
						break ;
					}
					currentA = currentA->next;
				}
			}
		}
		if(stack_len(*a) == 3)
			ft_sort3(a);
		else if (stack_len(*a) == 2)
		{
			if ((*a)->value > (*a)->next->value)
				ft_sa(a);
		}
		printf("_______________________________________________________________\n");
	}
	printf("stack a:\n");
	printstack(a);
	printf("stack b:\n");
	printstack(b);
}
