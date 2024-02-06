/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:59:09 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/05 17:11:59 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// sa: swap a
//- swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
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

// sb: swap b
//- swap the first 2 nodes at the top of stack b. Do nothing if there is only one or no nodes).
// void	ft_sb(t_stack **a)
// {
// 	t_stack	*tmp;
// 	t_stack	*third;

// 	if (!(*a) || !(*a)->next)
// 		return ;
// 	tmp = (*a);
// 	if (stack_len(*a) > 2)
// 	{
// 		third = ft_lst_last(*a);
// 		(*a) = (*a)->next;
// 		tmp->next = third;
// 		(*a)->next = tmp;
// 		tmp->prev = (*a);
// 		third->prev = tmp;
// 		(*a)->prev = NULL;
// 	}
// 	else
// 	{
// 		(*a) = (*a)->next;
// 		(*a)->next = tmp;
// 		(*a)->prev = NULL;
// 		tmp->prev = (*a);
// 		tmp->next = NULL;
// 	}
// 	write(1, "sb\n", 3);
// }

// // ss: sa and sb at the same time.
// void	ft_ss(t_stack **a, t_stack **b)
// {
// 	ft_sa(a);
// 	ft_sb(b);
// 	write(1, "ss\n", 3);
// }

// pa: push to a
//- take the first node at the top of b and put it at the top of a. Do nothing if b is empty.
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

// pb: push to b
//- take the first node at the top of a and put it at the top of b. Do nothing if a is empty.

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

// ra: rotate shift up all the nodes of a by 1. The first node becomes the last one.
void	ft_ra(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	if (!(*a) || !((*a)->next))
		return ;
	*a = ft_lst_last(*a);
	(*a)->next = tmp;
	tmp->prev = *a;
	*a = tmp->next; // revoit *a pointer sur le deuxieme element de la chaine
	tmp->next = NULL;
	// avant de couper le premier element du reste de la chaine
	(*a)->prev = NULL;
	write(1, "ra\n", 3);
}

// rb: rotate b
//- shift up all the nodes of b by 1. The first node becomes the last one.
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

// rr: ra and rb at the same time.
void	ft_rr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if ((!(*a) || !((*a)->next)) && (!(*b) || !((*b)->next)))
		return ;
	else
	{
		tmp = *a;
		if (!(*a) || !((*a)->next))
			return ;
		*a = ft_lst_last(*a);
		(*a)->next = tmp;
		tmp->prev = *a;
		*a = tmp->next;
		tmp->next = NULL;
		(*a)->prev = NULL;
		tmp = *b;
		if (!(*b) || !((*b)->next))
			return ;
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
	t_stack	*newfirstA;
	t_stack	*lastA;
	t_stack	*newfirstB;
	t_stack	*lastB;

	if (!*a || !(*a)->next)
		return ;
	lastA = ft_lst_last(*a)->prev;
	newfirstA = ft_lst_last(*a);
	newfirstA->next = *a;
	(*a)->prev = newfirstA;
	newfirstA->prev = NULL;
	lastA->next = NULL;
	*a = newfirstA;
	if (!*b || !(*b)->next)
		return ;
	lastB = ft_lst_last(*b)->prev;
	newfirstB = ft_lst_last(*b);
	newfirstB->next = *b;
	(*b)->prev = newfirstB;
	newfirstB->prev = NULL;
	lastB->next = NULL;
	*b = newfirstB;
	write(1, "rrr\n", 4);
}
