/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:15:42 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/24 23:28:57 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cheapest(t_stack **stack)
{
	t_stack *current;

	current = NULL;
	if ((*stack) == NULL)
		return ;
	current = ft_lst_last(*stack);
	while(current != NULL && current->prev != NULL)
	{
		if(current->push_cost < current->prev->push_cost)
			(*stack) = current->prev;
		current->cheapest = 0;
		current = current->prev;
	}
	(*stack)->cheapest = 1;
}
	