/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 20:43:40 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/09 06:48:21 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

// Utils
void	free_stack(t_stack *stack);
void	add_node(t_stack **a, int value);
int		ft_stacksize(t_stack *head);
t_stack	*ft_stacklast(t_stack *head);
void	index_nodes(t_stack **a);
long	ft_atol(char *str);
int		strlen_nbr(char *nbr);
int		get_min(t_stack **a);
int		get_max(t_stack **a);
int		get_min_index(t_stack **a);
int		get_max_index(t_stack **a);
int		get_index(t_stack **a, int min);
int		get_value_index(t_stack **a, int min);
int		get_next_min(t_stack **a, int min);

// Actions
void	sab(t_stack **head, char name);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rab(t_stack **ab, char name);
void	rr(t_stack **a, t_stack **b);
void	rrab(t_stack **ab, char name);
void	rrr(t_stack **a, t_stack **b);

// Normal sort
int		is_sorted(t_stack **a);
int		is_revsorted(t_stack **a);
void	sort_3(t_stack **a);
void	sort_5(t_stack **a, t_stack **b, int size);

// Radix
int		has_from_to(t_stack **a, int min, int max);
void	ft_radix(t_stack **a, t_stack **b);

// Insertion
void	push_chunk(t_stack **a, t_stack **b, int min, int max);
void	chuncker(t_stack **a, t_stack **b);
void	insertion(t_stack **a, t_stack **b);

// Pivot
void	migrate_to_b(t_stack **a, t_stack **b);
void	back_to_a(t_stack **a, t_stack **b);
void	init(t_stack **a, int *pivot1, int *pivot2, int *last_pivot);
int		position(t_stack *a, t_stack *b);
void	bottom_partition(t_stack **a, t_stack **b, int *n);
void	pivot(t_stack **a, t_stack **b);
void	top_partition(t_stack **a, t_stack **b, int *n);

// Parser
void	free_buff(char	**nbrs);
int		check_dup(t_stack **a);
int		check_argument(char **nbrs, t_stack **a);
int		fill_stack(int argc, char **argv, t_stack **a);
int		check_input(int argc, char **argv);

#endif
