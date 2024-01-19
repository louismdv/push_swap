/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:59:39 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/18 01:09:56 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// int	main(int ac, char *av[])
// {
// 	t_stack	*head;
// 	int		*tab;
// 	int		j;
// 	int		size;
// 	int		nums;

// 	tab = NULL;
// 	j = 0;
// 	nums = 0;
// 	size = ft_strlen(av[1]);
// 	if (ac == 1 || (ac == 2 && ft_strlen(av[1]) == 0))
// 		return (0);
// 	// ac == 2 -- ./push_swap "12 13 283 1"
// 	else if (ac == 2 && ft_strlen(av[1]) != 0)
// 	{
// 		if (check_num(av[1], size) != 1) //check input ints
// 			return (0);
// 		while (av[1][j])
// 		{
// 			if (av[1][j] >= '0' && av[1][j] <= '9' && (av[1][j + 1] == ' ' || av[1][j + 1] == '\0'))
// 				nums++; // count number of ints in input
// 			j++;
// 		}
// 		tab = (int *)malloc(nums * sizeof(int));
// 		if (!tab)
// 			return (0);
// 		j = 0;
// 		av = ft_split(av[1], ' '); // split input into tab of strings
// 		while (j <= nums && av[j])
// 		{
// 			tab[j] = ft_atol(av[j]); // create tab of ints from tab of strings
// 			printf("tab[%d] = %d\n", j, tab[j]);
// 			j++;
// 		}
// 		if (check_dup(tab, nums) != 1) // check dups
// 			return (0);
// 		printf("input ok\n");
// 	}
// 	// ac > 2 -- ./push_swap 12 13 283 1
// 	else if (ac > 2 && ft_strlen(av[1]) != 0)
// 	{
// 		tab = (int *)malloc((ac - 1) * sizeof(int));
// 		if (!tab)
// 			return (0);
// 		j = 0;
// 		while(j < ac && av[j+1])
// 		{
// 			if (check_num(av[j+1], ft_strlen(av[j+1])) != 1) // check input ints
// 				return (0);
// 			tab[j] = ft_atol(av[j+1]); // create tab of ints from tab of strings
// 			printf("tab[%d] = %d\n", j, tab[j]);
// 			j++;
// 		}
// 		if(check_dup(tab, ac - 1) != 1) //check input dups
// 			return (0);
// 		j = 0;
// 		while (tab[j])
// 		{
// 			append_node(&head, tab[j]);
// 			j++;
// 		}
// 	}
// }

// NOTES//

// either argc == 2 or argc > 2
// transform argc == 2 into tab of ints
// check if ints table is valide: no duplicate,no more than 1 space between each number,
//	no letters, no symbols,no more than 1 int
// then use split func to split input into nodes that for A stack
