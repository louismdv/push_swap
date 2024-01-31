/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:15:42 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/31 18:24:59 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cheapest(t_stack **stack)
{
	t_stack	*current1;
	t_stack	*current2;
	t_stack	*ptr_cheapest;

	printf("[searching cheapest node...]\n");
	current1 = (*stack);
	ptr_cheapest = current1;
	while (current1 != NULL)
	{
		current2 = current1->next;
		while (current2 != NULL)
		{
			if (current2->push_cost < ptr_cheapest->push_cost)
				ptr_cheapest = current2;
			current2 = current2->next;
		}
		current1 = current1->next;
	}
	if (ptr_cheapest != NULL)
		ptr_cheapest->cheapest = 1;
	current1 = (*stack);
	while (current1 != NULL)
	{
		printf("node value: [%d]-> cheapest: [%d]\n",
			current1->value, current1->cheapest);
		current1 = current1->next;
	}
	printf("\n");
}

void	init_cheapest(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		stack->cheapest = 0;
		stack = stack->next;
	}
}

void	init_b(t_stack **a, t_stack **b)
{
	ft_pb(a, b);
	ft_pb(a, b);
	if ((*b)->next == NULL)
		return ;
	else if (check_sort(*b) == 1) //make decr
		ft_sb(b);
}

void	bring_a2top(t_stack *currentA, t_stack **a)
{
	int targetIndex;

	targetIndex = currentA->index;
	if (!currentA || currentA->index == 0)
		return ;
	while ((*a)->index != targetIndex)
	{
		if (currentA->under_median == 1)
			ft_rra(a);
		else
			ft_sa(a);
		indexing(a);
	}
}

void	bring_b2top(t_stack *currentB, t_stack **b)
{
	if (!currentB || currentB->index == 0)
		return ;
	while (currentB->index != 0)
	{
		if (currentB->under_median == 1)
			ft_rrb(b);
		else
			ft_sb(b);
		indexing(b);
	}
}

void	printstack(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current != NULL)
	{
		printf("|_ node value: [%d]\n", current->value);
		current = current->next;
	}
	printf("\n");
}
