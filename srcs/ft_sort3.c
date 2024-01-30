/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:59:15 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/30 23:34:10 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_stack **a)
{
	int	value1;
	int	value2;
	int	value3;

	value1 = (*a)->value;
	value2 = (*a)->next->value;
	value3 = (*a)->next->next->value;
	//value2 < value1 && ...
	if (value2 < value3 && value1 < value2 && value1 < value3) // 3 9 10
		return ;
	else if (value2 < value3 && value1 < value3 && value1 > value2) // 9 3 10
		ft_sa(a);
	else if (value2 < value3 && value1 > value3 && value1 > value2) //10 3 9
		ft_ra(a);
	//value2 > value3 && ...
	else if (value2 > value3 && value1 < value2 && value1 < value3) // 3 10 9
	{
		ft_rra(a);
		ft_sa(a);
	}
	else if (value1 > value2 && value2 > value3 && value1 > value3) // 10 9 3
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if (value2 > value3 && value1 < value2 && value1 > value3) // 9 10 3
		ft_rra(a);
}


// v2 < v3
	// 3 9 10 -> value1 < value2 < value3 CHECK
	// 9 3 10 -> value1 > value2 < value3 sa
	// 10 3 9 -> value1 > value2 < value3 ra


// v2 > v3
	// 10 9 3 -> value1 > value2 > value3 sa rra
	// 3 10 9 -> value1 < value2 > value3 rra sa
	// 9 10 3 -> value1 > value2 > value3 rra
