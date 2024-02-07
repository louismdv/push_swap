/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ft_parse_quoted.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:58:33 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/07 21:12:58 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// This func counts the # of ints in the string.
int	count_int(char *str)
{
	int	j;
	int	nums;

	j = 0;
	nums = 0;
	while (str[j])
	{
		if (str[j] >= '0' && str[j] <= '9' && (str[j + 1] == ' ' || str[j
				+ 1] == '\0'))
			nums++;
		j++;
	}
	return (nums);
}

// This func does 3 things:
// 1. It checks if the input is a number.
// 2. It checks if the input has duplicates.
// 3. It creates a list of ints from the input.
t_stack	*ft_parse_quoted(char **av)
{
	long	*tab;
	t_stack	*stack_a;
	int		nums;

	tab = NULL;
	stack_a = NULL;
	if (check_num_quoted(av[1], ft_strlen(av[1])) == 0 || count_int(av[1]) < 1)
	{
		ft_error();
		return (0);
	}
	if (count_int(av[1]) == 1)
		return (0);
	nums = count_int(av[1]);
	tab = spliting(av, nums);
	if (ft_parse_quoted_checks(tab, nums) == 0)
	{
		ft_error_free(tab);
		return (0);
	}
	list_args(tab, &stack_a, nums);
	free(tab);
	return (stack_a);
}

int	ft_parse_quoted_checks(long *tab, int nums)
{
	if (check_dup_quoted(tab, nums) == 0 || check_intmax(tab, nums) == 0)
		return (0);
	return (1);
}

long	*spliting(char **av, int nums)
{
	char	**av1;
	int		j;
	long	*tab;

	j = 0;
	av1 = ft_split(av[1], ' ');
	if (av1 == NULL)
	{
		ft_error();
		exit(0);
	}
	tab = (long *)malloc(count_int(av[1]) * sizeof(long));
	if (!tab)
	{
		free_split_result(av1);
		exit(0);
	}
	while (j < nums && av1[j])
	{
		tab[j] = ft_atol(av1[j]);
		free(av1[j]);
		j++;
	}
	free(av1);
	// free_split_result(av1);
	return (tab);
}
