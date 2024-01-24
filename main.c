/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:52:18 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/24 23:30:27 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*currentA;
	t_stack	*currentB;

	b = NULL;
	a = NULL;
	a = init_stack(ac, av);
	if (!a)
	{
		printf("stack_a is empty\n");
		return (0);
	}
	if (!check_sort(&a))
	{
		if (stack_len(a) == 2)
			ft_sa(&a);
		else if (stack_len(a) == 3)
			ft_sort3(&a);
		// 	else
		// 		ft_sort(stack_a);
	}
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	if (b == NULL)
		printf("stack_b is empty\n");
	indexing(&a);
	indexing(&b);
	find_target_node(&a, &b);
	currentA = a;
	currentB = b;
	// TESTS costs calculation
	//
	while (currentA != NULL)
	{
		printf("\npush cost stackA node: %d is %d", currentA->value,
			push_cost_node(currentA, stack_len(a)));
		printf("\n under median: %d", currentA->under_median);
		currentA = currentA->next;
	}
	printf("\n");
	while (currentB != NULL)
	{
		printf("\npush cost stackB node: %d is %d", currentB->value,
			push_cost_node(currentB, stack_len(b)));
		printf("\n under median: %d", currentB->under_median);
		currentB = currentB->next;
	}
	printf("\n");
	currentA = a;
	while (currentA != NULL)
	{
		printf("\nTOTAL PUSH COST stackA node: %d is %d", currentA->value,
			total_cost(currentA, stack_len(a), stack_len(b)));
		printf("\n under median: %d\n", currentA->under_median);
		currentA = currentA->next;
	}
	
	currentA = a;
	printf("\n");
	printf("cheapest stackA:\n");
	cheapest(&a);
	while (currentA!= NULL)
	{
		printf("cheapest node %d: %d\n", currentA->value, currentA->cheapest);
		currentA = currentA->next;
	}

	printf("\n");
	currentB = b;
	printf("cheapest stackB:\n");
	cheapest(&b);
	while (currentB!= NULL)
	{
		printf("cheapest node %d: %d\n", currentB->value, currentB->cheapest);
		currentB = currentB->next;
	}

	printf("\n");
	while (a)
	{
		printf("stack_a element: `%d`\n", a->value);
		a = a->next;
	}

	printf("\n");
	while (b)
	{
		printf("stack_b element: `%d`\n", b->value);
		b = b->next;
	}
	ft_free_stack(&a);
}
