/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:59:09 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/29 23:19:28 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa: swap a
//- swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
void	ft_sa(t_stack **a)
{
	t_stack	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	tmp->prev = (*a);
	(*a)->next = tmp;
	(*a)->prev = NULL;
	write(1, "sa\n", 3);
}

// sb: swap b
//- swap the first 2 nodes at the top of stack b. Do nothing if there is only one or no nodes).
void	ft_sb(t_stack **b)
{
	t_stack	*tmp;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	tmp->prev = (*b);
	(*b)->next = tmp;
	(*b)->prev = NULL;
	write(1, "sb\n", 3);
}

// ss: sa and sb at the same time.
void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(&(*a));
	ft_sb(&(*b));
	write(1, "ss\n", 3);
}

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
		if(*b)
			(*b)->prev = NULL;
		(*a)->next = NULL;
	}
	else
	{
		tmp = *a;
		*a = *b;
		*b = (*b)->next;
		if(*b)
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
		if(*a)
			(*a)->prev = NULL;
		(*b)->prev = NULL;	
		(*b)->next = NULL;
	}
	else
	{
		tmp = *b;
		*b = *a;
		*a = (*a)->next;
		if(*a)
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
	*a = tmp->next; //revoit *a pointer sur le deuxieme element de la chaine
	tmp->next = NULL; // avant de couper le premier element du reste de la chaine
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
	if (!(*a) || !((*a)->next))
		return ;
	else
		ft_ra(&(*a));
	if (!(*b) || !((*b)->next))
		return ;
	else
		ft_rb(&(*b));
	write(1, "rr\n", 3);
}

// rra: reverse rotate a
//- shift down all the nodes of a by 1. The last node becomes the first one.
void ft_rra(t_stack **a) {
    if (!*a || !(*a)->next)
        return;

    int i = 0;
    t_stack *tmp = *a;

    // Find the last node and count the number of nodes
    while (tmp->next) {
        tmp = tmp->next;
        i++;
    }

    // Use a separate pointer to traverse the list to avoid modifying *a
    t_stack *current = *a;
    while (i > 1) {
        current = current->next;
        i--;
    }

    // Rearrange pointers to perform the rotation
    tmp->next = *a;
    current->next = NULL;
    (*a)->prev = NULL;

    write(1, "rra\n", 4);
}


// rrb: reverse rotate b
//- shift down all the nodes of b by 1. The last node becomes the first one.
void	ft_rrb(t_stack **b)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = NULL;
	if (!(*b) || !((*b)->next))
		return ;
	tmp = *b;
	while ((*b)->next)
	{
		(*b) = (*b)->next;
		i++;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	(*b)->prev = NULL;
	write(1, "rrb\n", 4);
}

// rrr: rra and rrb at the same time.
void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rra(&(*a));
	ft_rrb(&(*b));
	write(1, "rrr\n", 4);
}