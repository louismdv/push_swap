/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:35:24 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/01 14:45:21 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char *str, int size)
{
	int	j;

	j = 0;
	while (str[j] && j < size)
	{
		if (str[j] == '-' || str[j] == '+' || str[j] == ' ')
			j++;
		else if (ft_isdigit(str[j]))
			j++;
		else
		{
			//printf("not digit\n");
			return (0);
		}
	}
	return (1);
}

int	check_dup(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[j] == ' ' || tab[i] == ' ')
				j++;
			if (tab[i] == tab[j])
			{
				//printf("dup\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

// int	main(int ac, char *av[])
// {
// 	if (ac != 2)
// 		return (0);
// 	if (check_num(av[1], ft_strlen(av[1])) != 1)
// 		//printf("not integer\n");
// 	else
// 		printf("integer\n");
// 	return (0);
// }