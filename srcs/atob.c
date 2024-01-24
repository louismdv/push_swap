/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:01:58 by lmerveil          #+#    #+#             */
/*   Updated: 2024/01/24 16:44:32 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stack **stack)
{
	int		indexgo;
	int		median;
	t_stack	*current;

	current = (*stack);
	median = stack_len(current) / 2;
	indexgo = 0;
	if (current == NULL)
		return ;
	printf("stacklen: %d, median: %d\n", stack_len(current), median);
	while (current != NULL)
	{
		current->index = indexgo;
		if (indexgo > median)
			current->under_median = 1;
		else
			current->under_median = 0;
		printf("Node with value %d has index %d\n", current->value,
			current->index);
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
		while (currentB)
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
		printf("Node with value %d in stackA has target index %d in stackB\n",
			currentA->value, currentA->target_index);
		currentA = currentA->next;
	}
}

int	push_cost_node(t_stack *node, int stacklen)
{
	int	pushup_node;

	if (node == NULL)
		return (0);
	else if (node->under_median == 1)
		pushup_node = stacklen - (node->index);
	else
		pushup_node = node->index;
	return (pushup_node);
}

int	total_cost(t_stack *a, int stacklenA, int stacklenB)
{
	int	total_cost;

	total_cost = 0;
	if (a->target_index == -1)
	{
		total_cost = push_cost_node(a, stacklenA);
		a->push_cost = total_cost;
	}
	else
	{
		total_cost = push_cost_node(a, stacklenA)
			+ push_cost_node(a->target_node, stacklenB);
		a->push_cost = total_cost;
	}
	return (total_cost);
}
