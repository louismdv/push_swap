/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:52:18 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/24 12:01:46 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

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
	if(b == NULL)
		printf("stack_b is empty\n");
	indexing(&a);
	indexing(&b);
	find_target_node(&a, &b);
	while(a->next)
	{
		printf("\n");
		printf("push cost of stackA node: %d is %d\n", a->value, push_cost_a(&(*a)));
		a=a->next;
	}
	// while (a)
	// {
	// 	printf("stack_a element: `%d`\n", a->value);
	// 	a = a->next;
	// }
	// while (b)
	// {
	// 	printf("stack_b element: `%d`\n", b->value);
	// 	b = b->next;
	// }
	// ft_free_stack(&a);
	return (0);
}


