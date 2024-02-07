/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking_btoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:49:28 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/07 00:52:01 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	btoa(t_stack **a, t_stack **b)
{
	while (*b != NULL)
	{
		indexing(a);
		indexing(b);
		find_target_nodeb(a, b);
		bringtotop1(a, (*b)->target_node, 'a');
		ft_pa(a, b);
		if (*b == NULL)
			return ;
	}
}
