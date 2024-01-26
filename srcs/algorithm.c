/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:15:42 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/26 01:40:39 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cheapest(t_stack **stack)
{
	t_stack *current;
	t_stack *start;

	start = *stack;
	current = NULL;
	if ((*stack) == NULL)
		return ;
	current = ft_lst_last(*stack);
	while(current != NULL && current->prev != NULL)
	{
		if(current->push_cost < current->prev->push_cost)
			(*stack) = current;
		current->cheapest = 0;
		current = current->prev;
	}
	(*stack)->cheapest = 1;
	current = start;
	while(current != NULL)
	{
		printf("Node value: [%d]-> cheapest: [%d]\n", current->value, current->cheapest);
		current = current->next;
	}
	printf("\n");
}
void	init_b(t_stack **a, t_stack **b)
{
	ft_pb(a, b);
	ft_pb(a, b);
	if((*b)->next == NULL)
		return ;
	else if(check_sort(*b) == 0)
		ft_sb(b);
}

//enters if more than 3 nodes in A and A not sorted
void	ft_sort(t_stack **a, t_stack **b)
{	
	t_stack	*currentA;
	
	currentA = *a;

	while((!check_sort(*a)))
	{
		indexing(a);
		indexing(b);
		find_target_node(a, b);
		find_target_node(b, a);
		total_cost(&currentA, stack_len(*a), stack_len(*b));
		cheapest(a);
		cheapest(b);
		currentA = *a;
		while(currentA != NULL && currentA->next != NULL)
		{
			if((currentA)->cheapest == 1)
				ft_pb(&currentA, b);
			else
				currentA = currentA->next;
			printf("index: [%d], value: [%d], push_cost: [%d], cheapest: [%d]\n", (*a)->index, 
			(*a)->value, (*a)->push_cost, (*a)->cheapest);
		}
	}
	printf("_______________________________________________________________\n");
}