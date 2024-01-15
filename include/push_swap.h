/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:52:27 by louismdv          #+#    #+#             */
/*   Updated: 2024/01/15 11:08:55 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <stdlib.h>

typedef struct s_stack_node
{
	int						value;
	struct s_stack_node		*prev;
	struct s_stack_node		*next;
}				t_stack_node;

t_stack_node	*append_node(t_stack_node **head, int value);

#endif
