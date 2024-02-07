/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ft_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:48:23 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/07 00:59:56 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// This function does three things.
// 1. It checks if ac < 2 -> ft_error().
// 2. It checks if ac == 2. -> ft_parse_args_quoted(argv)
// 3. It checks if ac > 2 -> list_args(argv, &stack_a)

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (ac < 2 || (ac == 2 && ft_strlen(av[1]) == 0))
	{
		ft_error();
		return (0);
	}
	else if (ac == 2 && ft_strlen(av[1]) != 0)
		stack_a = ft_parse_quoted(av);
	else if (ac > 2 && ft_strlen(av[1]) != 0)
		stack_a = ft_parse_int(ac, av);
	return (stack_a);
}

void	ft_error_free(long *tab)
{
	free(tab);
	printf("Error\n");
}

void	ft_error(void)
{
	printf("Error\n");
}

// error
// ac ==2 && strlen(av[1] = 1 ou 0)
// av[1] not nums
// av[1] has dups
// av[1] is " "