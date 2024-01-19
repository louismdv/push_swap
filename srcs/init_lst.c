/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:46:22 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/18 15:31:20 by louismdv         ###   ########.fr       */
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
		ft_add_back(stack_a, ft_new_node(tab[i]));
		i++;
	}
}