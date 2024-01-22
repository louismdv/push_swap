/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:01:58 by lmerveil          #+#    #+#             */
/*   Updated: 2024/01/22 15:23:48 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// target_node
// cheapest_move

#include "push_swap.h"

t_stack	*target_node(t_stack *a, t_stack *b)
{
	while (a->value < b->value)
		b = b->next;
	if ()
}
