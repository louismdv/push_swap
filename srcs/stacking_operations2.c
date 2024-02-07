/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking_operations2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 00:15:04 by lmerveil          #+#    #+#             */
/*   Updated: 2024/02/07 00:31:22 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
// rr: ra and rb at the same time.
void	ft_rr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if ((!(*a) || !((*a)->next)) && (!(*b) || !((*b)->next)))
		return ;
	else
	{
		tmp = *a;
		*a = ft_lst_last(*a);
		(*a)->next = tmp;
		tmp->prev = *a;
		*a = tmp->next;
		tmp->next = NULL;
		(*a)->prev = NULL;
		tmp = *b;
		*b = ft_lst_last(*b);
		(*b)->next = tmp;
		tmp->prev = *b;
		*b = tmp->next;
		tmp->next = NULL;
		(*b)->prev = NULL;
	}
	write(1, "rr\n", 3);
}

// rra: reverse rotate a
//- shift down all the nodes of a by 1. The last node becomes the first one.
void	ft_rra(t_stack **a)
{
	t_stack	*newfirst;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	last = ft_lst_last(*a)->prev;
	newfirst = ft_lst_last(*a);
	newfirst->next = *a;
	(*a)->prev = newfirst;
	newfirst->prev = NULL;
	last->next = NULL;
	*a = newfirst;
	write(1, "rra\n", 4);
}

// rrb: reverse rotate b
//- shift down all the nodes of b by 1. The last node becomes the first one.
void	ft_rrb(t_stack **b)
{
	t_stack	*newfirst;
	t_stack	*last;

	if (!*b || !(*b)->next)
		return ;
	last = ft_lst_last(*b)->prev;
	newfirst = ft_lst_last(*b);
	newfirst->next = *b;
	(*b)->prev = newfirst;
	newfirst->prev = NULL;
	last->next = NULL;
	*b = newfirst;
	write(1, "rrb\n", 4);
}

// rrr: rra and rrb at the same time.
void	ft_rrr(t_stack **a, t_stack **b)
{
	t_stack	*newfirsta;
	t_stack	*lasta;
	t_stack	*newfirstb;
	t_stack	*lastb;

	if (!*a || !(*a)->next)
		return ;
	lasta = ft_lst_last(*a)->prev;
	newfirsta = ft_lst_last(*a);
	newfirsta->next = *a;
	(*a)->prev = newfirsta;
	newfirsta->prev = NULL;
	lasta->next = NULL;
	*a = newfirsta;
	if (!*b || !(*b)->next)
		return ;
	lastb = ft_lst_last(*b)->prev;
	newfirstb = ft_lst_last(*b);
	newfirstb->next = *b;
	(*b)->prev = newfirstb;
	newfirstb->prev = NULL;
	lastb->next = NULL;
	*b = newfirstb;
	write(1, "rrr\n", 4);
}
