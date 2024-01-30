/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:01:34 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/30 12:39:29 by lmerveil         ###   ########.fr       */
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
		while (stack_len(currentA) > 3)
		{
			// as long as /A not == 3, push cheapest node to B
			if (currentA != NULL)
			{
				currentA = *a;

				init_cheapest(*a);
				init_cheapest(*b);
				indexing(a);
				indexing(b);

				find_target_nodea(a, b);
				find_target_nodeb(a, b);

				total_cost(a, stack_len(*a), stack_len(*b));
				total_cost(b, stack_len(*a), stack_len(*b));

				cheapest(a);
				cheapest(b);

				currentA = *a;
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
						printf(GREEN ">>>>>>>>>> pushing node [%d] to B\n" RESET,
							currentA->value);
						ft_pb(&currentA, b);

						printf("stack a:\n");
						printstack(&currentA);
						printf("stack b:\n");
						printstack(b);
						break ;
					}
					currentA = currentA->next;
				}
			}
		}
		ft_sort3(&currentA);
		printf("_______________________________________________________________\n");
		printf("%d\n", stack_len(currentA));
	}
	printf("stack a:\n");
	printstack(&currentA);
	printf("stack b:\n");
	printstack(b);
}