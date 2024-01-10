/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort-3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 06:29:48 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/09 23:39:18 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bottom_partition(t_stack **a, t_stack **b, int *n)
{
	while ((*a)->index - 1 != (*b)->index && ft_stacksize(*b))
	{
		if (!(*n) || (*b)->index > ft_stacklast(*a)->index)
		{
			pa(a, b);
			rab(a, 'a');
			*n = 1;
		}
		else
			rrab(b, 'b');
	}
	pa(a, b);
}

void	top_partition(t_stack **a, t_stack **b, int *n)
{
	while ((*a)->index - 1 != (*b)->index)
	{
		if (!(*n) || (*b)->index > ft_stacklast(*a)->index)
		{
			pa(a, b);
			rab(a, 'a');
			*n = 1;
		}
		else
			rab(b, 'b');
	}
	pa(a, b);
}
