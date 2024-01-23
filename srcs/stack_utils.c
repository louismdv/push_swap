/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:53:53 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/23 13:34:40 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// makes node pointer point to last node of stack
t_stack	*ft_lst_last(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

// measures stack length
int	stack_len(t_stack *stack_a)
{
	int	i;

	i = 0;
	if (!stack_a)
		return (i);
	while (stack_a)
	{
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

// checks if stack is sort
bool	check_sort(t_stack **a)
{
	if (!(*a))
		return (0);
	while ((*a)->next)
	{
		if ((*a)->value > (*a)->next->value)
			(*a) = (*a)->next;
		else
			return (0);
	}
	return (1);
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

t_stack	*ft_find_max(t_stack **stack)
{
	t_stack	*max;

	max = NULL;
	if (!(*stack))
		return (max);
	max = (*stack);
	(*stack) = (*stack)->next;
	while ((*stack) != NULL)
	{
		if (max->value < (*stack)->value)
			max = (*stack);
		(*stack) = (*stack)->next;
	}
	return (max);
}

t_stack	*ft_find_min(t_stack **stack)
{
	t_stack	*min;

	min = NULL;
	if (*stack == NULL)
		return (min);
	min = *stack;
	(*stack) = (*stack)->next;
	while (*(stack) != NULL)
	{
		if (min->value > (*stack)->value)
			min = (*stack);
		(*stack) = (*stack)->next;
	}
	return (min);
}
