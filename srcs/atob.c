/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:01:58 by lmerveil          #+#    #+#             */
/*   Updated: 2024/01/26 17:16:55 by lmerveil         ###   ########.fr       */
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
	printf("[indexing...]\n");
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
		printf("Node value: [%d]-> index: [%d] -> under median: [%d]\n",
			current->value, current->index, current->under_median);
		current = current->next;
		indexgo++;
	}
	printf("\n");
}
void	find_target_node(t_stack **a, t_stack **b)
{
	t_stack	*currentA;
	t_stack	*currentB;
	t_stack	*closestInferiorNode;
	int		valDiff;
	int		minDiff;

	if (!(*a) || !(*b))
	{
		printf("[One of the stacks is empty.]\n");
		return ;
	}
	currentA = (*a);
	printf("[finding target nodes...]\n");
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
			currentA->target_node = closestInferiorNode;
		else
			currentA->target_node = ft_find_max(*b);
		printf("node value: [%d]-> target index [%d] in stackB\n",
			currentA->value, currentA->target_node->index);
		currentA = currentA->next;
	}
	printf("\n");
}

int	push_cost_node(t_stack *node, int stacklen)
{
	int	pushup_node;

	// printf("[calculating push cost...]\n");
	if (node == NULL)
		return (0);
	else if (node->under_median == 1)
		pushup_node = stacklen - (node->index);
	else
		pushup_node = node->index;
	// printf("push cost [%d]: %d\n", node->value, pushup_node);
	return (pushup_node);
}

int	total_cost(t_stack **stack, int stacklenA, int stacklenB)
{
	int		total_cost;
	t_stack	*current;

	current = (*stack);
	printf("[calculating total cost...]\n");
	total_cost = 0;
	while (current != NULL)
	{
		total_cost = push_cost_node(current, stacklenA)
			+ push_cost_node(current->target_node, stacklenB);
		current->push_cost = total_cost;
		printf("total cost [%d]: %d\n", current->value, total_cost);
		current = current->next;
	}
	return (total_cost);
}
