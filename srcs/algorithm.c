/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:15:42 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/26 18:44:27 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cheapest(t_stack **stack)
{
	t_stack	*current1;
	t_stack	*current2;
	t_stack	*ptr_cheapest;
	int		valDiff;
	int		minDiff;

	printf("\n");
	printf("[searching cheapest node...]\n");
	current1 = (*stack);
	while (current1 != NULL)
	{
		current2 = current1->next;
		ptr_cheapest = NULL; // Initialize ptr_cheapest for each current1
		minDiff = INT_MAX;
		while (current2 != NULL)
		{
			valDiff = current1->push_cost - current2->push_cost;
			if (valDiff >= 0 && valDiff < minDiff)
			{
				ptr_cheapest = current2;
				minDiff = valDiff;
			}
			current2 = current2->next;
		}
		if (ptr_cheapest != NULL)
		{
			ptr_cheapest->cheapest = 1;
		}
		printf("node value: [%d]-> cheapest [%d]\n", current1->value,
			current1->cheapest);
		current1 = current1->next;
	}
	printf("\n");
}

// void	cheapest(t_stack **stack)
// {
// 	t_stack	*current;
// 	t_stack	*start;

// 	start = *stack;
// 	current = NULL;
// 	if (*stack == NULL)
// 		return ;
// 	current = ft_lst_last(*stack);
// 	while ()
// 	{
// 		while (current != NULL && current->prev != NULL)
// 		{
//
// 		}
// 	}
// 	if (*stack != NULL)
// 		(*stack)->cheapest = 1;
// 	current = start;
// 	while (current != NULL)
// 	{
// 		printf("Node value: [%d]-> cheapest: [%d]\n", current->value,
// 			current->cheapest);
// 		current = current->next;
// 	}
// 	printf("\n");
// }

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
		cheapest(&currentA);
		// cheapest(&currentB);
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