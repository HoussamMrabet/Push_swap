/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort-2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:30:01 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/09 06:52:04 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position(t_stack *a, t_stack *b)
{
	int	pos;
	int	size;

	size = ft_stacksize(b) / 2;
	pos = a->index - 1;
	while (size--)
	{
		if (pos == b->index)
			return (1);
		b = b->next;
	}
	return (0);
}

void	back_to_a(t_stack **a, t_stack **b)
{
	int	n;
	int	last_a;

	last_a = ft_stacklast(*a)->index;
	n = 0;
	while (ft_stacksize(*b))
	{
		if (!position(*a, *b))
			bottom_partition(a, b, &n);
		else
			top_partition(a, b, &n);
		while ((*a)->index - 1 == ft_stacklast(*a)->index)
			rrab(a, 'a');
		if (ft_stacklast(*a)->index == last_a)
			n = 0;
	}
}

void	init(t_stack **a, int *pivot1, int *pivot2, int *last_pivot)
{
	*last_pivot = *pivot1;
	*pivot2 = ft_stacksize(*a) / 6 + *pivot1;
	*pivot1 += ft_stacksize(*a) / 3;
}

void	migrate_to_b(t_stack **a, t_stack **b)
{
	int	pivot1;
	int	pivot2;
	int	last_pivot;

	last_pivot = -1;
	pivot2 = ft_stacksize(*a) / 6;
	pivot1 = ft_stacksize(*a) / 3;
	while (ft_stacksize(*a) > 3)
	{
		if (ft_stacksize(*b) > 1 && (*b)->index < pivot2 \
			&& (*b)->index > last_pivot && (*a)->index > pivot1)
			rr(a, b);
		else if (ft_stacksize(*b) > 1 && (*b)->index < pivot2 \
			&& (*b)->index > last_pivot)
			rab(b, 'b');
		if ((*a)->index < pivot1)
			pb(a, b);
		else
			rab(a, 'a');
		if (ft_stacksize(*b) >= pivot1)
			init(a, &pivot1, &pivot2, &last_pivot);
	}
}

void	pivot(t_stack **a, t_stack **b)
{
	migrate_to_b(a, b);
	sort_3(a);
	back_to_a(a, b);
}
