/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:49:28 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/01 18:39:19 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	btoa(t_stack **a, t_stack **b)
{
	while ((*b)->next)
	{
		indexing(a);
		indexing(b);
		find_target_nodeb(a, b);
		bringToTop(a, (*b)->target_node, 'a');
		ft_pa(a, b);
		*b = (*b)->next;
	}
}
