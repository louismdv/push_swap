/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking_operations1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:59:09 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/07 00:23:07 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sa(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*third;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = (*a);
	if (stack_len(*a) > 2)
	{
		third = ft_lst_last(*a);
		(*a) = (*a)->next;
		tmp->next = third;
		(*a)->next = tmp;
		tmp->prev = (*a);
		third->prev = tmp;
		(*a)->prev = NULL;
	}
	else
	{
		(*a) = (*a)->next;
		(*a)->next = tmp;
		(*a)->prev = NULL;
		tmp->prev = (*a);
		tmp->next = NULL;
	}
	write(1, "sa\n", 3);
}

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	if (!(*a))
	{
		*a = *b;
		*b = (*b)->next;
		if (*b)
			(*b)->prev = NULL;
		(*a)->next = NULL;
	}
	else
	{
		tmp = *a;
		*a = *b;
		*b = (*b)->next;
		if (*b)
			(*b)->prev = NULL;
		(*a)->next = tmp;
		tmp->prev = *a;
	}
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	if (!(*b))
	{
		*b = *a;
		*a = (*a)->next;
		if (*a)
			(*a)->prev = NULL;
		(*b)->prev = NULL;
		(*b)->next = NULL;
	}
	else
	{
		tmp = *b;
		*b = *a;
		*a = (*a)->next;
		if (*a)
			(*a)->prev = NULL;
		(*b)->next = tmp;
		tmp->prev = *b;
	}
	write(1, "pb\n", 3);
}

void	ft_ra(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	if (!(*a) || !((*a)->next))
		return ;
	*a = ft_lst_last(*a);
	(*a)->next = tmp;
	tmp->prev = *a;
	*a = tmp->next;
	tmp->next = NULL;
	(*a)->prev = NULL;
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	if (!(*b) || !((*b)->next))
		return ;
	*b = ft_lst_last(*b);
	(*b)->next = tmp;
	tmp->prev = *b;
	*b = tmp->next;
	tmp->next = NULL;
	(*b)->prev = NULL;
	write(1, "rb\n", 3);
}
