/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmerveil <lmerveil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:52:27 by louismdv          #+#    #+#             */
/*   Updated: 2024/02/07 00:55:31 by lmerveil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define RESET "\x1B[0m"

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
	int				index;
	int				push_cost;
	bool			under_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*prev;
}					t_stack;

// parsing
int					check_num(char *str, int size);
int					check_dup(long *tab, int size);
long				ft_atol(const char *nptr);
t_stack				*init_stack(int ac, char **av);
t_stack				*ft_parse_int(int ac, char **av);
t_stack				*ft_parse_quoted(char **av);
void				list_args(long *tab, t_stack **stack_a, int size);
void				ft_error_free(long *tab);
void				ft_error(void);
void				free_split_result(char **result);
int					check_intmax(long *tab, int size);
int					ft_parse_int_checks(int ac, long *tab);
int					ft_parse_quoted_checks(long *tab, int nums);
long				*spliting(char **av, int nums);

// node manipulation
t_stack				*ft_new_node(int content);
t_stack				*ft_lst_last(t_stack *node);
int					stack_len(t_stack *stack);
void				add_node_back(t_stack **stack, t_stack *newnode);
void				ft_free_stack(t_stack **a);

// operations
void				ft_sa(t_stack **stack_a);
// void				ft_sb(t_stack **b);
// void				ft_ss(t_stack **a, t_stack **b);
void				ft_pa(t_stack **a, t_stack **b);
void				ft_pb(t_stack **a, t_stack **b);
void				ft_ra(t_stack **a);
void				ft_rb(t_stack **b);
void				ft_rr(t_stack **a, t_stack **b);
void				ft_rra(t_stack **a);
void				ft_rrb(t_stack **b);
void				ft_rrr(t_stack **a, t_stack **b);
t_stack				*valdiffb(t_stack *currenta, int mindiff,
						t_stack *closestsup, t_stack *currentb);
t_stack				*valdiffa(t_stack *currenta, int maxdiff,
						t_stack *closestinf, t_stack *currentb);

// algorithm
void				ft_sort3(t_stack **a);
bool				check_sort(t_stack *stack);
t_stack				*ft_find_max(t_stack *stack);
t_stack				*ft_find_min(t_stack *stack);
void				indexing(t_stack **stack);
void				find_target_nodeb(t_stack **a, t_stack **b);
void				find_target_nodea(t_stack **s1, t_stack **s2);
int					push_cost_node(t_stack *node, int stacklen);
int					total_cost(t_stack **a, int stacklena, int stacklenb);
t_stack				*cheapest(t_stack **stack);
void				atob(t_stack **a, t_stack **b);
void				atob_suite(t_stack *currenta, t_stack **b, t_stack **a);
void				btoa(t_stack **a, t_stack **b);
void				init_b(t_stack **a, t_stack **b);
void				init_cheap_target(t_stack *stack);
void				bringtotop1(t_stack **stack, t_stack *top_node, char name);
void				bringtotop2(t_stack **a, t_stack *top_nodea, t_stack **b,
						t_stack *top_nodeb);

#endif