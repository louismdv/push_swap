/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:59:15 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/19 20:14:00 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_3sort(t_stack **a)
{
	int value1;
	int	value2;
	int	value3;

	value1 = (*a)->value;
	value2 = (*a)->next->value;
	value3 = (*a)->next->next->value;

	if(value1 < value2 && value2 < value3)
		return ;
	else if(value1 > value2 && value2 < value3)
	{
		if(value1 < value3) // 9 3 10
			ft_sa(&(*a));
		else // 10 3 9
			ft_ra(&(*a));
	}
	else if(value1 > value2 && value2 > value3) //10 9 3
	{
		ft_sa(&(*a));
		ft_ra(&(*a));
	}
	else if(value1 < value2 && value2 > value3) 
	{
		if(value1 < value3) // 3 10 9
		{
			ft_sa(&(*a));
			ft_ra(&(*a));
		}
		else // 7 9 3
			ft_rra(&(*a));
	}
}
