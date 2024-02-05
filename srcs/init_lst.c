/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:46:22 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/05 17:12:12 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// This func creates a newnode with the content of tab[i]
// and adds it to the end of the stack_a list.
void	list_args(int *tab, t_stack **stack_a, int size)
{
	long	i;

	i = 0;
	while (i < size)
	{
		add_node_back(stack_a, ft_new_node(tab[i]));
		i++;
	}
}

t_stack	*ft_new_node(int content)
{
	t_stack *newnode;

	newnode = malloc(sizeof(t_stack));
	if (!newnode)
		return (NULL);
	newnode->value = content;
	newnode->prev = NULL;
	newnode->next = NULL;
	return (newnode);
}

void	add_node_back(t_stack **stack, t_stack *newnode)
{
	t_stack	*last;

	if (*stack == NULL)
	{
		*stack = newnode;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = newnode;
	newnode->prev = last;
}
