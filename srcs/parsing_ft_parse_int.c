/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:28:50 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/05 18:09:46 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_parse_int(int ac, char **av)
{
	int		j;
	long	*tab;
	t_stack	*stack_a;

	j = 0;
	stack_a = NULL;
	tab = (long *)malloc((ac - 1) * sizeof(long));
	if (!tab)
		return (0);
	while (j < ac && av[j + 1])
	{
		if (check_num(av[j + 1], ft_strlen(av[j + 1])) != 1)
		{
			ft_error_free(tab);
			return (0);
		}
		tab[j] = ft_atol(av[j + 1]);
		j++;
	}
	if (check_dup(tab, ac) == 0 || check_intmax(tab, ac) == 0)
	{
		ft_error_free(tab);
		return (0);
	}
	list_args(tab, &stack_a, ac - 1);
	free(tab);
	return (stack_a);
}
