/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking_target_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:01:58 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/07 00:59:21 by lmerveil         ###   ########.fr       */
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

// closest inferior target node -> smallest positive difference
void	find_target_nodea(t_stack **a, t_stack **b)
{
	t_stack	*currenta;
	t_stack	*currentb;
	t_stack	*closestinf;
	int		maxdiff;

	if (!(*a) || !(*b))
		return ;
	currenta = (*a);
	while (currenta != NULL)
	{
		currentb = (*b);
		closestinf = NULL;
		maxdiff = INT_MAX;
		closestinf = valdiffa(currenta, maxdiff, closestinf, currentb);
		if (closestinf != NULL)
			currenta->target_node = closestinf;
		else
			currenta->target_node = ft_find_max(*b);
		currenta = currenta->next;
	}
}

// closest superior target node -> smallest negative difference
void	find_target_nodeb(t_stack **a, t_stack **b)
{
	t_stack	*currenta;
	t_stack	*currentb;
	t_stack	*closestsup;
	int		mindiff;

	if (!(*a) || !(*b))
		return ;
	currentb = (*b);
	while (currentb != NULL)
	{
		currenta = (*a);
		closestsup = NULL;
		mindiff = INT_MIN;
		closestsup = valdiffb(currenta, mindiff, closestsup, currentb);
		if (closestsup != NULL)
			currentb->target_node = closestsup;
		else
			currentb->target_node = ft_find_min(*a);
		currentb = currentb->next;
	}
}

t_stack	*valdiffb(t_stack *currenta, int mindiff,
				t_stack *closestsup, t_stack *currentb)
{
	int	valdiff;

	while (currenta != NULL)
	{
		valdiff = currentb->value - currenta->value;
		if (valdiff < 0 && valdiff > mindiff)
		{
			closestsup = currenta;
			mindiff = valdiff;
		}
		currenta = currenta->next;
	}
	return (closestsup);
}

t_stack	*valdiffa(t_stack *currenta, int maxdiff,
				t_stack *closestinf, t_stack *currentb)
{
	int	valdiff;

	while (currentb)
	{
		valdiff = currenta->value - currentb->value;
		if (valdiff > 0 && valdiff < maxdiff)
		{
			closestinf = currentb;
			maxdiff = valdiff;
		}
		currentb = currentb->next;
	}
	return (closestinf);
}
