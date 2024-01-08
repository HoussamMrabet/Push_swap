/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 20:43:40 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/06 16:00:38 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"
# include "get_next_line.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

// utils
void	free_stack(t_stack *stack);
void	add_node(t_stack **a, int value);
int		ft_stacksize(t_stack *head);
t_stack	*ft_stacklast(t_stack *head);
long	ft_atol(char *str);
int		is_sorted(t_stack **a);

// actions
void	sab(t_stack **head);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rab(t_stack **ab);
void	rr(t_stack **a, t_stack **b);
void	rrab(t_stack **ab);
void	rrr(t_stack **a, t_stack **b);

// parser
void	free_buff(char	**nbrs, int start);
int		check_dup(t_stack **a);
int		check_argument(char **nbrs, t_stack **a);
int		fill_stack(int argc, char **argv, t_stack **a);
int		check_input(int argc, char **argv);

#endif