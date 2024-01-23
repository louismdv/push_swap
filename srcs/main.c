/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:52:18 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/22 22:59:55 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = init_stack(ac, av);
	if(!stack_a){
		printf("stack_a is empty\n");
		return (0);
	}
	if(!ft_sort(stack_a))
	{	
		if(stack_len(stack_a) == 2)
			ft_sa(&stack_a);
		else if (stack_len(stack_a) == 3)
			ft_sort3(&stack_a);
	}
	while (stack_a)
	{
		printf("stack_a element: `%d`\n", stack_a->value);
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		printf("stack_b element: `%d`\n", stack_b->value);
		stack_b = stack_b->next;
	}
	ft_free_stack(&stack_a);
	return (0);
}