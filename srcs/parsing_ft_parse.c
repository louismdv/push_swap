/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ft_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:48:23 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/08 18:44:56 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (ac < 2)
		return (0);
	else if (ft_strlen(av[1]) == 0)
		ft_error();
	else if (ac == 2 && (ft_atol(av[1]) > 2147483647
			|| ft_atol(av[1]) < -2147483648))
		ft_error();
	else if (ac > 2 && ft_strlen(av[1]) != 0)
		stack_a = ft_parse_int(ac, av);
	else if (ac == 2 && ft_strlen(av[1]) != 0)
		stack_a = ft_parse_quoted(av);
	return (stack_a);
}

void	ft_error_free(long *tab)
{
	free(tab);
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}
