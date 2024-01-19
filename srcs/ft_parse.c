/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:48:23 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/19 20:21:12 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function does three things.
// 1. It checks if ac < 2 -> ft_error().
// 2. It checks if ac == 2. -> ft_parse_args_quoted(argv)
// 3. It checks if ac > 2 -> list_args(argv, &stack_a)

t_stack	*ft_parse(int ac, char **av)
{
	t_stack		*stack_a;
	
	stack_a = NULL;
	if (ac < 2)
		return (stack_a);
	else if (ac == 2 && ft_strlen(av[1]) != 0)
		stack_a = ft_parse_quoted(av);
	else if (ac > 2 && ft_strlen(av[1]) != 0)
		stack_a = ft_parse_int(ac, av);
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_parse(ac, av);
	ft_set_stack_to3(&stack_a, &stack_b);
	ft_3sort(&stack_a);
	while(stack_a)
	{
		printf("stack_a element: `%d`\n", stack_a->value);
		stack_a = stack_a->next;
	}
	while(stack_b)
	{
		printf("stack_b element: `%d`\n", stack_b->value);
		stack_b = stack_b->next;
	}
	return (0);
}
