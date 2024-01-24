/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:01:58 by lmerveil          #+#    #+#             */
/*   Updated: 2024/01/24 11:50:46 by louismdv         ###   ########.fr       */
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
	t_stack	*current;

	current = (*stack);
	median = stack_len(current) / 2;
	indexgo = 0;
	if (current == NULL)
		return ;
	while (current != NULL)
	{
		current->index = indexgo;
		if (indexgo >= median)
			current->above_median = 1;
		else
			current->above_median = 0;
		// printf("Node with value %d has index %d\n", current->value, current->index);
		current = current->next;
		indexgo++;
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
		while (currentB && currentB->next)
		{
			valDiff = currentA->value - currentB->value;
			if (valDiff > 0 && valDiff < minDiff)
			{
				closestInferiorNode = currentB;
				minDiff = valDiff;
			}
			currentB = currentB->next;
		}
		if (closestInferiorNode != NULL)
			{
				currentA->target_index = closestInferiorNode->index;
				currentA->target_node = closestInferiorNode;
			}
		else
			currentA->target_index = -1;
		printf("Node with value %d in stackA has target index %d in stackB\n", currentA->value, currentA->target_index);
		currentA = currentA->next;
	}
}

int	push_cost_a(t_stack *node)
{
	int	pushupA;
	
	if((node) == NULL)
		return 0;
	if((node)->above_median)
		pushupA = stack_len((node)) - ((node)->index) + 1;
	else (pushupA = (node)->index);
	return(pushupA);
}

// push cost = 
// (#operations to bring a node on top A/) 
// + 
// (#operations ot bring a target node on top of B/)