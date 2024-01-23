/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:01:58 by lmerveil          #+#    #+#             */
/*   Updated: 2024/01/23 15:07:01 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// target_node
// cheapest_move

#include "push_swap.h"

// t_stack	*target_node(t_stack *a, t_stack *b)
// {
// 	while (a->value < b->value)
// 		b = b->next;
// 	if ()
// }

void	indexing(t_stack **stack)
{
	int	indexgo;
	int	median;

	median = stack_len(*stack) / 2;
	indexgo = 0;
	if ((*stack) == NULL)
		return ;
	while ((*stack) != NULL)
	{
		(*stack)->index = indexgo;
		if (indexgo >= median)
			(*stack)->above_median = 1;
		else
			(*stack)->above_median = 0;
		(*stack) = (*stack)->next;
		++indexgo;
	}
}
void	find_target_node(t_stack **a, t_stack **b)
{
	t_stack	*currentA;
	t_stack	*currentB;
	t_stack	*closestInferiorNode;
	int		valDiff;
	int		minDiff;

	currentA = (*a);
	while (currentA != NULL)
	{
		currentB = (*b);
		closestInferiorNode = NULL;
		minDiff = INT_MAX;
		while (currentB != NULL)
		{
			valDiff = currentA->value - currentB->value;
			if (valDiff > 0 && valDiff < minDiff)
			{
				closestInferiorNode = currentB;
				printf("nodeA %d target node: %d\n", currentA->value,
					closestInferiorNode->value);
				minDiff = valDiff;
			}
			currentB = currentB->next;
			if (closestInferiorNode != NULL)
				currentA->target_index = closestInferiorNode->index;
			else
				currentA->target_index = -1;
		}
		currentA = currentA->next;
	}
}

// void	push_cost(t_stack **a)
// {
// 	if((*a) == NULL)

// }