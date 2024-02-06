/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:15:42 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/05 17:12:06 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*cheapest(t_stack **stack)
{
	t_stack	*current1;
	t_stack	*current2;
	t_stack	*ptr_cheapest;

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
		current1 = current1->next;
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

void	bringToTop1(t_stack **stack, t_stack *top_node, char name)
{
	while (top_node != *stack)
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

void	bringToTop2(t_stack **a, t_stack *top_nodeA, t_stack **b, t_stack *top_nodeB)
{
	while (*a != top_nodeA && *b != top_nodeB)
	{
		if (!top_nodeA->under_median && !top_nodeB->under_median)
			ft_rr(a, b);
		else if (top_nodeA->under_median && top_nodeB->under_median)
			ft_rrr(a, b);
		else if (!top_nodeA->under_median && top_nodeB->under_median)
		{
			ft_ra(a);
			ft_rrb(b);
		}
		else if (top_nodeA->under_median && !top_nodeB->under_median)
		{
			ft_rra(a);
			ft_rb(b);
		}
		
	}
}

void	optimoves(t_stack **a, t_stack *top_nodeA, t_stack **b, t_stack *top_nodeB)
{
	int	lenA;
	int lenB;
	int indexA;
	int indexB;

	int aboveA;
	int underA;
	int aboveB;
	int underB;


	lenA = stack_len(*a);
	lenB = stack_len(*b);
	indexA = top_nodeA->index;
	indexB = top_nodeB->index;
	
	aboveA = indexA;
	underA = lenA - indexA;

	aboveB = indexB;
	underB = lenB - indexB;

	//topA index > topB index && A above median && b under median && aboveA + underB < aboveB
	//----> rr(a,b);

	if(!(top_nodeA->under_median) && (top_nodeB->under_median) && indexA < indexB)
	{
		if(aboveA + underB < aboveB)
			while(top_nodeA != *a)
				ft_rr(a,b);
		// if(aboveA < (indexA + aboveB))
		// 	while(top_nodeA != *a)
		// 		ft_rrr(a,b);
	}
	else if((top_nodeA->under_median) && !(top_nodeB->under_median) && indexA > indexB)
	{
		if(underA + aboveB < aboveA)
			while(top_nodeB != *b)
				ft_rr(a,b);
	}
}
