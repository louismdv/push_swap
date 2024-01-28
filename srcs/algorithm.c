/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:15:42 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/29 00:41:51 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cheapest(t_stack **stack)
{
	t_stack	*current1;
	t_stack	*current2;
	t_stack	*ptr_cheapest;

	printf("\n");
	printf("[searching cheapest node...]\n");
   	current1 = (*stack);
	ptr_cheapest = current1;
    while (current1 != NULL)
    {
        current2 = current1->next;
        while (current2 != NULL)
        {
            if (current2->push_cost < ptr_cheapest->push_cost)
                ptr_cheapest = current2;
            current2 = current2->next;
        }
        current1 = current1->next;
    }
    if (ptr_cheapest != NULL)
        ptr_cheapest->cheapest = 1;
    current1 = (*stack);
    while (current1 != NULL)
    {
        printf("node value: [%d]-> push_cost: [%d]->cheapest: [%d]\n", current1->value, current1->push_cost, current1->cheapest);
        current1 = current1->next;
    }
	printf("\n");
}

void	init_b(t_stack **a, t_stack **b)
{
	ft_pb(a, b);
	ft_pb(a, b);
	if ((*b)->next == NULL)
		return ;
	else if (check_sort(*b) == 0)
		ft_sb(b);
}

// enters if more than 3 nodes in A and A not sorted
void	ft_sort(t_stack **a, t_stack **b)
{
	t_stack *currentA;
	t_stack *currentB;

	if (check_sort(*a) == 0)
	{
		currentA = *a;
		currentB = *b;

		indexing(&currentA);
		indexing(&currentB);
		find_target_node(&currentA, &currentB);
		find_target_node(&currentB, &currentA);
		total_cost(a, stack_len(*a), stack_len(*b));
		total_cost(b, stack_len(*b), stack_len(*a));
		cheapest(&currentA);
		cheapest(&currentB);
		currentA = *a;
		while (currentA != NULL && currentA->next != NULL)
		{
			if ((currentA)->cheapest == 1)
				ft_pb(&currentA, b);
			else
				currentA = currentA->next;
			printf("index: [%d], value: [%d], push_cost: [%d]\n", (*a)->index,
				(*a)->value, (*a)->push_cost);
		}
	}
	printf("_______________________________________________________________\n");
}