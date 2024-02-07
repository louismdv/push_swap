/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_push_cost.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 00:12:35 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/07 00:25:47 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

	current = (*stack);
	total_cost = 0;
	while (current != NULL)
	{
		total_cost = push_cost_node(current, stacklenA)
			+ push_cost_node(current->target_node, stacklenB);
		current->push_cost = total_cost;
		current = current->next;
	}
	return (total_cost);
}
	// opti_cost = optipush(stack, stacklenA, stacklenB);
	// if (total_cost > opti_cost)
	// 	current->push_cost = opti_cost;
	// else		// opti_cost = optipush(stack, stacklenA, stacklenB);
	// if (total_cost > opti_cost)
	// 	current->push_cost = opti_cost;
	// else
	//
// int	optipush(t_stack **stack, int stacklenA, int stacklenB)
// {
// 	t_stack *node;
// 	int opti_cost;
// 	node = *stack;
// 	int indexA = node->index;
// 	int indexB = node->target_node->index;
// 	int belowB = stacklenB - node->target_node->index;
// 	int belowA = stacklenA - indexA;
//
// 	opti_cost = 2147483647;
//
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
//
// 	return (2147483647);
// }