/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:01:58 by lmerveil          #+#    #+#             */
/*   Updated: 2024/01/30 11:19:56 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stack **stack)
{
	int		indexgo;
	int		median;
	t_stack	*current;

	current = (*stack);
	median = (stack_len(current) - 1) / 2;
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
		printf("Node value: [%d]-> index: [%d]\n", current->value,
			current->index);
		current = current->next;
		indexgo++;
	}
	printf("\n");
}
void	find_target_nodea(t_stack **a, t_stack **b)
// closest inferior target node -> smallest positive difference
{
	t_stack *currentA;
	t_stack *currentB;
	t_stack *closestInferiorNode;
	int valDiff;
	int maxDiff;

	if (!(*a) || !(*b))
	{
		printf("[One of the stacks is empty.]\n");
		return ;
	}
	currentA = (*a);
	printf(GREEN "[finding target nodes for stackA...]\n" RESET);
	while (currentA != NULL)
	{
		currentB = (*b);
		closestInferiorNode = NULL;
		maxDiff = INT_MAX;
		while (currentB)
		{
			valDiff = currentA->value - currentB->value;
			// printf("node: [%d], value [%d]\n", currentA->value, valDiff);
			if (valDiff > 0 && valDiff < maxDiff)
			{
				closestInferiorNode = currentB;
				maxDiff = valDiff;
			}
			currentB = currentB->next;
		}
		if (closestInferiorNode != NULL)
			currentA->target_node = closestInferiorNode;
		else
			currentA->target_node = ft_find_max(*b);
		printf("node value: [%d]-> target index [%d]\n", currentA->value,
			currentA->target_node->index);
		currentA = currentA->next;
	}
	printf("\n");
}

void	find_target_nodeb(t_stack **a, t_stack **b)
// closest superior target node -> smallest negative difference
{
	t_stack *currentA;
	t_stack *currentB;
	t_stack *closestSuperiorNode;
	int valDiff;
	int minDiff;

	if (!(*a) || !(*b))
	{
		printf(RED "[stackB is empty.]\n" RESET);
		return ;
	}
	currentB = (*b);
	printf(GREEN "[finding target nodes for stackB...]\n" RESET);
	while (currentB != NULL)
	{
		currentA = (*a);
		closestSuperiorNode = NULL;
		minDiff = INT_MIN;
		while (currentA != NULL)
		{
			valDiff = currentB->value - currentA->value;
			// printf("node: [%d], value [%d]\n", currentB->value, valDiff);
			if (valDiff < 0 && valDiff > minDiff)
			{
				closestSuperiorNode = currentA;
				minDiff = valDiff;
			}
			currentA = currentA->next;
		}
		if (closestSuperiorNode != NULL)
			currentB->target_node = closestSuperiorNode;
		else
			currentB->target_node = ft_find_min(*a);
		printf("node value: [%d]-> target index [%d]\n", currentB->value,
			currentB->target_node->index);
		currentB = currentB->next;
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
		// printf("total cost [%d]: %d\n", current->value, total_cost);
		current = current->next;
	}
	return (total_cost);
}
