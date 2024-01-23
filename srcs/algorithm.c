/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:15:42 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/22 22:19:40 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_sort(t_stack **a)
{
	if (!(*a))
		return(0);
	while((*a)->next)
	{
		if ((*a)->value > (*a)->next->value)
			(*a) = (*a)->next;
		else
			return(0);
	}
	return (1);
}

// void	cost(t_stack **a, t_stack **b)
// {
// 	while (*b)
// 	{
// 	}
// }

