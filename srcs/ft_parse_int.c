/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:28:50 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/23 11:29:38 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_parse_int(int ac, char **av)
{
	int		j;
	int		*tab;
	t_stack	*stack_a;

	j = 0;
	stack_a = NULL;
	tab = (int *)malloc((ac - 1) * sizeof(int));
	if (!tab)
		return (0);
	while (j < ac && av[j + 1])
	{
		if (check_num(av[j + 1], ft_strlen(av[j + 1])) != 1)
			return (stack_a);
		tab[j] = ft_atol(av[j + 1]);
		j++;
	}
	if (check_dup(tab, ac - 1) != 1)
		return (stack_a);
	list_args(tab, &stack_a, ac - 1);
	free(tab);
	return (stack_a);
}
