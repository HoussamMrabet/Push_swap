/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort-1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:59:37 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/09 06:25:54 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion(t_stack **a, t_stack **b)
{
	int		max;
	t_stack	*tmp;
	int		size;
	int		i;

	size = ft_stacksize(*b);
	while (size > 0)
	{
		max = get_max_index(b);
		i = get_index(b, max);
		tmp = *b;
		while (tmp)
		{
			if (tmp->index == max)
				break ;
			if (i < (size / 2))
				rab(b, 'b');
			else
				rrab(b, 'b');
			tmp = *b;
		}
		tmp = *b;
		pa(a, b);
		size = ft_stacksize(*b);
	}
}

int	has_from_to(t_stack **a, int min, int max)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->index >= min && tmp->index <= max)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	push_chunk(t_stack **a, t_stack **b, int min, int max)
{
	t_stack	*tmp;

	tmp = *a;
	while (has_from_to(a, min, max))
	{
		tmp = *a;
		if (tmp->index >= min && tmp->index <= max)
			pb(a, b);
		else
			rab(a, 'a');
	}
}

void	chuncker(t_stack **a, t_stack **b)
{
	push_chunk(a, b, 0, 19);
	push_chunk(a, b, 20, 39);
	push_chunk(a, b, 40, 59);
	push_chunk(a, b, 60, 79);
	push_chunk(a, b, 80, 99);
	insertion(a, b);
}
