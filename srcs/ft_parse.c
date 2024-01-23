/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:48:23 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/22 22:32:19 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function does three things.
// 1. It checks if ac < 2 -> ft_error().
// 2. It checks if ac == 2. -> ft_parse_args_quoted(argv)
// 3. It checks if ac > 2 -> list_args(argv, &stack_a)

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (ac < 2)
		return (stack_a);
	else if (ac == 2 && ft_strlen(av[1]) != 0)
		stack_a = ft_parse_quoted(av);
	else if (ac > 2 && ft_strlen(av[1]) != 0)
		stack_a = ft_parse_int(ac, av);
	return (stack_a);
}
