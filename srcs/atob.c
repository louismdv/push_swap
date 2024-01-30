/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:01:34 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/29 23:32:11 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	atob(t_stack **a, t_stack **b)
{
	t_stack *currentA;
	t_stack *Atarget;

	printf(RED"[AtoB: ...]\n"RESET);
	if (check_sort(*a) == 0)
	{
		currentA = *a;
		while(stack_len(*a) > 3)
		{
			//as long as /A not == 3, push cheapest node to B
			if (currentA != NULL)
			{
				currentA = *a;
				Atarget = currentA->target_node;
				init_cheapest(*a);
				init_cheapest(*b);
				indexing(a);
				indexing(b);

				find_target_nodea(a,b);
				find_target_nodeb(b,a);

				total_cost(a, stack_len(*a), stack_len(*b));
				total_cost(b, stack_len(*a), stack_len(*b));
				
				cheapest(a);
				cheapest(b);

				while(currentA != NULL)
				{
					if(currentA->cheapest == 1)
					{
						bring_a2top(currentA);
						bring_b2top(Atarget);
						ft_pb(&currentA,b);
						printf(GREEN ">>>>>>>>>> pushing node [%d] to B\n" RESET, currentA->value );
						printf("stack a:\n");
						printstack(a);
						printf("stack b:\n");
						printstack(b);
						break;
					}
					currentA = currentA->next;
				}
			}
		}
		ft_sort3(a);
	printf("_______________________________________________________________\n");
	}
	printf("stack a:\n");
		printstack(a);
	printf("stack b:\n");
		printstack(b);
}