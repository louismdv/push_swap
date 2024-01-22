/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:15:42 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/22 13:58:31 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_stack_to3(t_stack **a, t_stack **b)
{
	while (ft_size(*a) > 3)
		ft_pb(&(*a), &(*b));
}

void	ft_sort(t_stack **b)
{
	if ((*b)->value < (*b)->next->value)
		ft_sb(&(*b));
	return ;
}

// void	cost(t_stack **a, t_stack **b)
// {
// 	while (*b)
// 	{
// 	}
// }

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_parse(ac, av);
	// ft_ra(&stack_a);
	ft_set_stack_to3(&stack_a, &stack_b);
	// ft_sort(&stack_b);
	while (stack_a)
	{
		printf("stack_a element: `%d`\n", stack_a->value);
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		printf("stack_b element: `%d`\n", stack_b->value);
		stack_b = stack_b->next;
	}
	return (0);
}
