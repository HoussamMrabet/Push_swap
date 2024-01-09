/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort-3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 06:29:48 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/09 06:47:26 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bottom_partition(t_stack **stack_a, t_stack **stack_b, int *b)
{
	while ((*stack_a)->index - 1 != (*stack_b)->index && ft_stacksize(*stack_b))
	{
		if (!(*b) || (*stack_b)->index > ft_stacklast(*stack_a)->index)
		{
			pa(stack_a, stack_b);
			rab(stack_a, 'a');
			*b = 1;
		}
		else
			rrab(stack_b, 'b');
	}
	pa(stack_a, stack_b);
}

void	top_partition(t_stack **stack_a, t_stack **stack_b, int *b)
{
	while ((*stack_a)->index - 1 != (*stack_b)->index)
	{
		if (!(*b) || (*stack_b)->index > ft_stacklast(*stack_a)->index)
		{
			pa(stack_a, stack_b);
			rab(stack_a, 'a');
			*b = 1;
		}
		else
			rab(stack_b, 'b');
	}
	pa(stack_a, stack_b);
}
