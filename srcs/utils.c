/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:15:42 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/01 18:23:14 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*cheapest(t_stack **stack)
{
	t_stack	*current1;
	t_stack	*current2;
	t_stack	*ptr_cheapest;

	// printf("[searching cheapest node...]\n");
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
		// printf("node value: [%d]-> cheapest: [%d]\n", current1->value,
		/* 	current1->cheapest); */
		current1 = current1->next;
	}
	// printf("\n");
	return (ptr_cheapest);
}

void	init_cheap_target(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		stack->target_node = 0;
		stack->cheapest = 0;
		stack = stack->next;
	}
}

void	init_b(t_stack **a, t_stack **b)
{
	if (stack_len(*a) > 3 && !check_sort(*a))
		ft_pb(a, b);
	if (stack_len(*a) > 3 && !check_sort(*a))
		ft_pb(a, b);
}

void	bring_a2top(t_stack *currentA, t_stack **a)
{
	if (!currentA || currentA->index == 0)
		return ;
	while (currentA->index != 0)
	{
		// printf(GREEN "currentA index:%d et target_index: %d\n" RESET,
		// currentA->index, currentA->target_node->index);
		if (currentA->under_median == true)
		{
			// printf("under_median: %d, currentA value: %d\n",
			// currentA->under_median, currentA->value);
			ft_rra(a);
		}
		else
			ft_ra(a);
		indexing(a);
	}
}

void	bringToTop(t_stack **stack, t_stack *top_node, char name)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (!top_node->under_median)
				ft_ra(stack);
			else
				ft_rra(stack);
		}
		else if (name == 'b')
		{
			if (!top_node->under_median)
				ft_rb(stack);
			else
				ft_rrb(stack);
		}
	}
}

void	bring_b2top(t_stack *currentB, t_stack **b)
{
	int	targetIndex;

	printf("entered");
	if (!currentB || currentB->index == 0 || !(*b))
	{
		printf("exited");
		return ;
	}
	targetIndex = currentB->index;
	while (currentB->index != 0)
	{
		if (currentB->under_median == 1)
			ft_rrb(b);
		else
			ft_rb(b);
		indexing(b);
		break ;
	}
}

void	printstack(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	if (current->target_node != NULL)
	{
		while (current != NULL)
		{
			printf("%d\n", current->value);
			current = current->next;
		}
	}
	else
	{
		while (current != NULL)
		{
			printf("|_ node value: [%d], cheapflag: [%d]\n", current->value,
				current->cheapest);
			current = current->next;
		}
	}
	// printf("\n");
}
