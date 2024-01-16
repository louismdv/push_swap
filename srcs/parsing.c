/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:59:39 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/16 15:16:11 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check input is valide :
// ./push_swap "12 13 283 1" or ./push_swap 12 13 283 1

#include "push_swap.h"

t_stack_node	*append_node(t_stack_node **head, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*last;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	if (*head == NULL) // if list is empty new node is head
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}
	else // else find last node and append new node
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
		return (new_node);
	}
}

int	main(int ac, char *av[])
{
	int	*tab;
	int	i;
	int	j;
	int	size;
	int	nums;

	tab = NULL;
	i = 0;
	j = 0;
	nums = 1;
	size = ft_strlen(av[1]) + 1;
	if (ac == 1 || (ac == 2 && ft_strlen(av[1]) == 0))
		return (0);
	// ac == 2
	else if (ac == 2 && ft_strlen(av[1]) != 0)
	{
		if (check_num(av[1], size) != 1)
			return (0);
		while (av[1][j])
		{
			if (av[i][j] == ' ')
				nums++;
			j++;
		}
		tab = (int *)malloc((ac - 1) * sizeof(int));
		if (!tab)
			return (0);
		j = 0;
		while (j < size && av[j])
		{
			tab[j] = atoi(av[j]);
			j++;
		}
	}
	// else if (ac > 2 && ft_strlen(av[1]) != 0)
	// {
	// 	tab = (int *)malloc((ac - 1) * sizeof(int));
	// 	if (!tab)
	// 		return (0);
	// 	j = 0;
	// 	while (j < size && av[j])
	// 	{
	// 		tab[j] = atoi(av[j]);
	// 		j++;
	// 	}
	// }
}
// else if (ac > 2) // input already in tab of ints
// {
// 	tab = malloc(sizeof(int) * (ac));
// 	if (!tab)
// 	{
// 		free(tab);
// 		return (0); //"error malloc"
// 	}
// 	i = 1;
// 	if (check_args(tab) != 1)
// 		return (check_args(tab));
// 	// check args inf to ints bounds
// 	// check args are ints
// 	while (i < ac)
// 	{
// 		tab[i - 1] = ft_atoi(av[i]);
// 		i++;
// 	}
// }
// while (tab[i][j])
// {
// 	if (check_dup(tab[i][j]), tab[i + 1][j])
// 		i++;
// 	else
// 		printf("dup");
// 	return (0);
// }
// 	{
// 		i = 0;
// 		while (tab[i])
// 		{
// 			printf("tab[%d] = %d\n", i, tab[i]);
// 			append_node(&head, tab[i]);
// 			i++;
// 		}
// 	}

// NOTES//

// either argc == 2 or argc > 2
// transform argc == 2 into tab of ints
// check if ints table is valide: no duplicate,no more than 1 space between each number,
//	no letters, no symbols,no more than 1 int
// then use split func to split input into nodes that for A stack

// to transform the ac ==2 input into tab of ints:
// - count number of numbers in input
// - malloc tab of ints
// - fill tab of ints with numbers from input

// then proceed with check if tab is valide

// algorithm

// output

// ft_split

// is input already integers? or not
// put in tab all the numbers from input
// check if all the numbers are digits
// check if there is no duplicate
// check  if there is no more than 1 space between each number

// fill stack_t

// algorithm