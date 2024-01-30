/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:15:42 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/30 12:02:29 by lmerveil         ###   ########.fr       */
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
		printf("node value: [%d]-> push_cost: [%d]->cheapest: [%d]\n",
			current1->value, current1->push_cost, current1->cheapest);
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

// Plangloi code
// void	cheapest(t_stack *stack)
// {
// 	t_stack *cheapest_node;
// 	int	cheapest_value;
// 	t_stack	*start;

// 	start = stack;
// 	cheapest_value = INT_MAX;
// 	while(stack)
// 	{
// 		if(stack->push_cost < cheapest_value)
// 		{
// 			cheapest_node = stack;
// 			cheapest_value = stack->push_cost;
// 		}
// 		stack = stack->next;
// 	}
//     if (cheapest_node != NULL)
//         cheapest_node->cheapest = 1;
//     while (start != NULL)
//     {
//         printf("node value: [%d]-> push_cost: [%d]->cheapest: [%d]\n",
// start->value, start->push_cost, start->cheapest);
//         start = start->next;
//     }
// 	printf("\n");
// }

void	init_b(t_stack **a, t_stack **b)
{
	ft_pb(a, b);
	ft_pb(a, b);
	if ((*b)->next == NULL)
		return ;
	else if (!check_sort(*b))
		ft_sb(b);
}

void	bring_a2top(t_stack *current, t_stack **stacka)
{
	if (!current)
		return ;
	while (current->index != 0)
	{
		if (current->under_median == 1)
			ft_rra(stacka);
		else
			ft_sa(stacka);
	}
}

void	bring_b2top(t_stack *current, t_stack **stackb)
{
	if (!current)
		return ;
	while (current->index != 0)
	{
		if (current->under_median == 1)
			ft_rrb(stackb);
		else
			ft_sb(stackb);
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
