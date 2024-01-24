/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:15:42 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/24 17:53:56 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*cheapest(t_stack **a)
{
	t_stack *currentA;

	currentA = NULL;
	if ((*a) == NULL)
		return (currentA);
	currentA = (*a);
	(*a) = (*a)->next;
	while ((*a) != NULL)
	{
		(*a)->cheapest = 0;
		if (currentA->push_cost > (*a)->push_cost)
			currentA = (*a);
		(*a) = (*a)->next;
	}
	currentA->cheapest = 1;
	return (currentA);
}