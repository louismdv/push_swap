/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:35:24 by lmerveil          #+#    #+#             */
/*   Updated: 2024/01/16 15:16:42 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char *str, int size)
{
	int	j;

	j = 0;
	while (str[j] && j < size)
	{
		if ((str[j] == '-' || str[j] == '+'))
			j++;
		if (ft_isdigit(str[j]))
		{
			j++;
			printf("is integer: %d", str[j]);
		}
		else
		{
			printf("input not integer format: %c\n", str[j]);
			return (0);
		}
	}
	return (1);
}
