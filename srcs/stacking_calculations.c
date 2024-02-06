/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking_calculations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:01:58 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/06 18:31:42 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	while (current != NULL)
	{
		current->index = indexgo;
		if (indexgo > median)
			current->under_median = true;
		else
			current->under_median = false;
		current = current->next;
		indexgo++;
	}
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
		return ;
	currentA = (*a);
	while (currentA != NULL)
	{
		currentB = (*b);
		closestInferiorNode = NULL;
		maxDiff = INT_MAX;
		while (currentB)
		{
			valDiff = currentA->value - currentB->value;
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
		currentA = currentA->next;
	}
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
		return ;
	currentB = (*b);
	while (currentB != NULL)
	{
		currentA = (*a);
		closestSuperiorNode = NULL;
		minDiff = INT_MIN;
		while (currentA != NULL)
		{
			valDiff = currentB->value - currentA->value;
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
		currentB = currentB->next;
	}
}

int	push_cost_node(t_stack *node, int stacklen)
{
	int	pushup_node;

	if (node == NULL)
		return (0);
	else if (node->under_median == true)
		pushup_node = stacklen - (node->index);
	else
		pushup_node = node->index;
	return (pushup_node);
}

int	total_cost(t_stack **stack, int stacklenA, int stacklenB)
{
	int		total_cost;
	t_stack	*current;

	// int		opti_cost;
	current = (*stack);
	total_cost = 0;
	while (current != NULL)
	{
		total_cost = push_cost_node(current, stacklenA)
			+ push_cost_node(current->target_node, stacklenB);
		// opti_cost = optipush(stack, stacklenA, stacklenB);
		// if (total_cost > opti_cost)
		// 	current->push_cost = opti_cost;
		// else
		current->push_cost = total_cost;
		current = current->next;
	}
	return (total_cost);
}

// int	optipush(t_stack **stack, int stacklenA, int stacklenB)
// {
// 	t_stack *node;
// 	int opti_cost;
// 	node = *stack;
// 	int indexA = node->index;
// 	int indexB = node->target_node->index;
// 	int belowB = stacklenB - node->target_node->index;
// 	int belowA = stacklenA - indexA;

// 	opti_cost = 2147483647;

// 	if (indexA > indexB)
// 	{
// 		if ((indexA + belowB) > indexA)
// 			opti_cost = indexA;
// 		if ((indexB + belowA) < belowB)
// 			opti_cost = belowB;
// 	}
// 	else if (indexA < indexB)
// 	{
// 		if ((indexB + belowA) > indexB)
// 			opti_cost = indexB;
// 		if ((indexA + belowB) < belowA)
// 			opti_cost = belowA;
// 	}

// 	return (2147483647);
// }