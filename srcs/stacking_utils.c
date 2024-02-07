/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:53:53 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/07 00:29:50 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// makes node pointer point to last node of stack
t_stack	*ft_lst_last(t_stack *node)
{
	if (!node && !node->next)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

// measures stack length
int	stack_len(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (i);
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

// free memory locations of each node in stack
void	ft_free_stack(t_stack **a)
{
	t_stack	*tmp;

	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
}

t_stack	*ft_find_max(t_stack *stack)
{
	t_stack	*max;

	max = NULL;
	if (!stack)
		return (max);
	max = stack;
	stack = stack->next;
	while (stack != NULL)
	{
		if (max->value < stack->value)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack	*ft_find_min(t_stack *stack)
{
	t_stack	*min;

	min = NULL;
	if (!stack)
		return (min);
	min = stack;
	stack = stack->next;
	while (stack != NULL)
	{
		if (min->value > stack->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}
