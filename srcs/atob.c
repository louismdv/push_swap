/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:01:58 by lmerveil          #+#    #+#             */
/*   Updated: 2024/01/23 11:27:38 by lmerveil         ###   ########.fr       */
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

	median = stacklen(&stack) / 2;
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
	
}