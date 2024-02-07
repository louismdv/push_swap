/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking_ft_sort3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:59:15 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/07 00:33:45 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort3(t_stack **a)
{
	int	value1;
	int	value2;
	int	value3;

	value1 = (*a)->value;
	value2 = (*a)->next->value;
	value3 = (*a)->next->next->value;
	if (value2 < value3 && value1 < value2 && value1 < value3)
		return ;
	else if (value2 < value3 && value1 < value3 && value1 > value2)
		ft_sa(a);
	else if (value2 < value3 && value1 > value3 && value1 > value2)
		ft_ra(a);
	else if (value2 > value3 && value1 < value2 && value1 < value3)
	{
		ft_rra(a);
		ft_sa(a);
	}
	else if (value1 > value2 && value2 > value3 && value1 > value3)
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if (value2 > value3 && value1 < value2 && value1 > value3)
		ft_rra(a);
}

	// 3 9 10 -> CHECK
	// 9 3 10 -> sa
	// 10 3 9 -> ra
	// 3 10 9 -> rra sa
	// 10 9 3 -> sa rra
	// 9 10 3 -> rra

// checks if stack is sort
// returns 1 if stack is sort, 0 if not
// check crescendo
bool	check_sort(t_stack *stack)
{
	if (!stack)
		return (false);
	while (stack->next != NULL)
	{
		if (stack->value < stack->next->value)
			stack = stack->next;
		else
			return (false);
	}
	return (true);
}
