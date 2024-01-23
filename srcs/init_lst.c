/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:46:22 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/22 22:29:23 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void	add_node_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}
