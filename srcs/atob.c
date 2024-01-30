/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:01:34 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/30 23:45:41 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	atob(t_stack **a, t_stack **b)
{
	t_stack *currentA;
	t_stack *Atarget;

	printf(RED "[AtoB: ...]\n" RESET);
	if (!check_sort(*a))
	{
		currentA = *a;
		while (stack_len(*a) > 3)
		{
			// as long as /A not == 3, push cheapest node to B
			if (currentA != NULL)
			{
				init_cheapest(*a);
				init_cheapest(*b);
				indexing(a);
				indexing(b);
				
				find_target_nodea(a, b);

				total_cost(a, stack_len(*a), stack_len(*b));
				total_cost(b, stack_len(*a), stack_len(*b));

				cheapest(a);
				cheapest(b);
				currentA = *a;
				printf(GREEN"Astacklen: %d\n"RESET, stack_len(*a));
				while (currentA != NULL)
				{
					if (currentA->cheapest == 1)
					{
						Atarget = currentA->target_node;
						printf("currentA: %d\n", currentA->value);
						printf("Atarget: %d\n", Atarget->value);
						bring_a2top(currentA, a);

						printf("stackA:\n");
						printstack(a);
						bring_b2top(Atarget, b);
						printf("stackB:\n");
						printstack(b);
						printf(GREEN ">>>>>>>>>> pushing node [%d] to B\n" RESET, currentA->value);
						ft_pb(a, b);
						printf(GREEN"Astacklen: %d\n"RESET, stack_len(*a));
						printf("top stack a: %d\n", (*a)->value);
						printf("stack a:\n");
						printstack(a);
						printf("stack b:\n");
						printstack(b);
						printf("value of a: %d\n", (*a)->value);
						printf("value of currentA: %d\n\n", currentA->value);
						break ;
					}
					currentA = currentA->next;
				}
			}
		}
		// printf("%d\n", stack_len(*a));
		ft_sort3(a);
		// printf("%d\n", stack_len(*a));
		// printf("stack a:\n");
		// printstack(a);
		printf("_______________________________________________________________\n");
	}
	printf("stack a:\n");
	printstack(a);
	printf("stack b:\n");
	printstack(b);
}