/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:59:39 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/14 00:20:11 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check input is valide :
// ./push_swap "12 13 283 1" or ./push_swap 12 13 283 1

#include "push_swap.h"
#include <limits.h>

int	main(int ac, char **av)
{
	t_stack_node	*head;
	t_stack_node	*node;
	int				**tab;
	int				i;
	int				j;
	
	head = NULL;
	node = NULL;
	if(ac == 1 || (ac == 2 && ft_strlen(av[1]) == 0))
		return (0);
	else if (ac == 2) // ./push_swap "12 13 283 1"
	{
		i = 0;
		j = 0;
		while (av[1][i]) // count j number of spaces between numbers
		{
			if (av[1][i] == ' ')
				j++;
			i++;
		}
		if (j == 0)
			return (0); //"error no space between numbers"
		tab = ft_split(av[1], ' '); // tab = ["12", "13", "283", "1"]
		tab = ft_atoi(tab); // tab = [12, 13, 283, 1]
		i = 0;
		while (tab[i])
		{
			if (ft_isdigit(tab[i]) == 0)
				return (0); //"error not a digit"
			if(tab[i] > INT_MAX || tab[i] < INT_MIN)
				return (0); //"error out of int bounds"
			append_node(&head, (int)tab[i]);
			i++;
		}
	}
	else // ./push_swap 12 13 283 1
	{
		i = 0;
		
		while (av[i])
		{
			if (ft_isdigit(av[i]) == 0)
				return (0); // error not a digit
			if(av[i] > INT_MAX || av[i] < INT_MIN)
				return (0); // error out of int bounds
			append_node(&head, (int)av[i]);
			i++;
		}
	}
	printf("head->value = %d\n", head->value);
}

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
		

// either argc == 2 or argc > 1

// then use split func to split input into nodes that for A stack

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