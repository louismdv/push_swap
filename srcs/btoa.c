/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:49:28 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/31 19:12:46 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	btoa(t_stack **a, t_stack **b)
{
	t_stack	*currentB;
	t_stack	*Btarget;

	currentB = *b;
	printf(RED "[BtoA: ...]\n" RESET);
	while (currentB != NULL)
	{
		currentB = *b;
		init_cheapest(*a);
		init_cheapest(*b);
		indexing(a);
		indexing(b);
		find_target_nodeb(a, b);
		total_cost(a, stack_len(*a), stack_len(*b));
		total_cost(b, stack_len(*b), stack_len(*a));
		cheapest(a);
		cheapest(b);
		printf(GREEN"Bstacklen: %d\n"RESET, stack_len(*b));
		while(currentB != NULL)
		{
			if (currentB->cheapest == 1)
			{
				Btarget = currentB->target_node;
				if(Btarget != NULL)
				{
					printf("currentB: %d\n", currentB->value);
					printf("Btarget: %d\n", Btarget->value);
					bring_b2top(currentB, b);
					bring_a2top(Btarget, a);
					ft_pa(a, b);
					printf(GREEN ">>>>>>>>>> pushing node [%d] to A\n" RESET, currentB->value);
						break ;
				}
				else
					return;
			}
			
		currentB = currentB->next;
		}
	}
	printf("_______________________________________________________________\n");
	printf("stack a:\n");
	printstack(a);
	printf("stack b:\n");
	printstack(b);
}
