/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_quoted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:58:33 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/18 09:52:28 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This func counts the # of ints in the string.
int	count_int(char *str)
{
	int	j = 0;
	int	nums = 0;

	while(str[j])
	{
		if (str[j] >= '0' && str[j] <= '9' && (str[j + 1] == ' ' || str[j + 1] == '\0'))
			nums++;
		j++;
	}
	return(nums);
}

// This func does 3 things:
// 1. It checks if the input is a number.
// 2. It checks if the input has duplicates.
// 3. It creates a list of ints from the input.
t_stack	*ft_parse_quoted(char **av)
{
	int			j;
	int			*tab;
	t_stack		*stack_a;
	int			nums;

	tab = NULL;
	stack_a = NULL;
	if (check_num(av[1], ft_strlen(av[1])) != 1)
		return (stack_a);
	tab = (int *)malloc(count_int(av[1]) * sizeof(int));
	if (!tab)
		return (stack_a);
	nums = count_int(av[1]);
	av = ft_split(av[1], ' ');
	j = 0; 
	while (j <= nums && av[j])
	{
		tab[j] = ft_atol(av[j]);
		j++;
	}
	if (check_dup(tab, nums) != 1)
		return (stack_a);
	list_args(tab, &stack_a, nums);
	free(tab);
	return(stack_a);
}
