/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:53:53 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/22 22:59:39 by louismdv         ###   ########.fr       */
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

int	stack_len(t_stack *stack_a)
{
	int i;

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

bool	ft_sort(t_stack *a)
{
	if(!(a))
		return(0);
	while(a->next)
	{
		if(a->value > a->next->value)
			a = a->next;
		else
			return(0);
	}
	return(1);
}

void	ft_free_stack(t_stack **a)
{
	t_stack	*tmp;
	
	while(*a)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
}