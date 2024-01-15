/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:59:39 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/15 15:57:24 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check input is valide :
// ./push_swap "12 13 283 1" or ./push_swap 12 13 283 1

#include "push_swap.h"
#include <limits.h>

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

int	check_num(int **tab)
{
	int i;
	int	j;

	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] && (tab[i][j] == '-' || tab[i][j] == '+'))
			j++;
		while (tab[i][j])
		{
			if (ft_isdigit(tab[i][j]) != 0)
				j++;
			else
			{
				printf("input not integer format: %d\n", *tab[i]);
				return(0);
			}
		}
		i++;
	}
	return(1);
}

int	check_dup(int **tab)
{
	int	i = 0;
	int j = 0;

	while(tab[i])
	{
		while(tab[i+1][j] == tab)
	}
}

int	main(int ac, char *av[])
{
	t_stack_node	*head;
	int				*tab;
	char			**temp;
	int				i;
	int				count_num;
	
	head = NULL;
	tab = NULL;
	temp = NULL;

	i = 0;
	count_num = 0;
	
	if(ac == 1 || (ac == 2 && ft_strlen(av[1]) == 0))
	{
		printf("no input\n");
		return (0);
	}
	else if (ac == 2 && ft_strlen(av[1]) != 0) //format input av into tab of ints
	{
		while (av[1][i])
		{
			if (av[1][i] == ' ')
				count_num++;
			i++;
		}
		temp = malloc(sizeof(char) * (count_num + 2)); // tab = ["12", "13", "283", "1"]
		if (!temp)
		{
			free(temp);
			return (0); //"error malloc"
		}
		temp = ft_split(av[1], ' '); // tab = ["12", "13", "283", "1"]
		
		tab = malloc(sizeof(int) * (count_num + 2));
		if (!tab)
		{
			free(tab);
			return (0); //"error malloc"
		}

		i = 0;
		while (temp[i])
		{
			tab[i] = ft_atoi(temp[i]); // tab = [12, 13, 283, 1]
			// printf("tab[%d] = %d\n", i, tab[i]);
			i++;
		}
	}
	else if (ac > 2) //input already in tab of ints
	{
		tab = malloc(sizeof(int) * (ac + 1));
		if (!tab)
		{
			free(tab);
			return (0); //"error malloc"
		}
		i = 1;
		while (i < ac)
		{
			tab[i - 1] = ft_atoi(av[i]);
			// printf("tab[%d] = %d\n", i - 1, tab[i - 1]);
			i++;
		}
	}
	if(check_num(&tab))
	{
		i = 0;
		while (tab[i])
		{
			printf("tab[%d] = %d\n", i, tab[i]);
			append_node(&head, tab[i]);
			i++;
		}
	}
}


		//NOTES//
		
// either argc == 2 or argc > 2
// transform argc == 2 into tab of ints
// check if ints table is valide: no duplicate, no more than 1 space between each number, no letters, no symbols, no more than 1 int
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