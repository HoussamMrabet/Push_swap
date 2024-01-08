/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort-0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:10:00 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/07 23:58:49 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **a)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = *a;
	tmp2 = *a;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->value > tmp2->value)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

int	is_revsorted(t_stack **a)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = *a;
	tmp2 = *a;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->value < tmp2->value)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

void	sort_3(t_stack **a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*a)->value;
	n2 = (*a)->next->value;
	n3 = (*a)->next->next->value;
	if (n1 < n2 && n1 < n3 && n2 > n3)
	{
		sab(a, 'a');
		rab(a, 'a');
	}
	else if (n1 > n2 && n1 < n3 && n2 < n3)
		sab(a, 'a');
	else if (n1 < n2 && n1 > n3 && n2 > n3)
		rrab(a, 'a');
	else if (n1 > n2 && n1 > n3 && n2 < n3)
		rab(a, 'a');
	else if (n1 > n2 && n1 > n3 && n2 > n3)
	{
		rab(a, 'a');
		sab(a, 'a');
	}
}

void	sort_5(t_stack **a, t_stack **b, int size)
{
	t_stack	*tmp;
	int		min;
	int		i;

	while (size >= 4)
	{
		min = get_min(a);
		i = get_value_index(a, min);
		tmp = *a;
		while (tmp)
		{
			if (tmp->value == min)
				break ;
			if (i <= (size / 2))
				rab(a, 'a');
			else
				rrab(a, 'a');
			tmp = *a;
		}
		pb(a, b);
		size--;
	}
	sort_3(a);
	pa(a, b);
	pa(a, b);
}

void	ft_radix(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		len;
	int		max_bits;
	int		i;
	int		j;

	len = ft_stacksize(*a);
	max_bits = 0;
	while ((len - 1) >> max_bits != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits && !(is_sorted(a)))
	{
		j = -1;
		while (++j < len && !(is_sorted(a) && is_revsorted(b)))
		{
			tmp = *a;
			if (((tmp->index >> i) & 1) == 1)
				rab(a, 'a');
			else
				pb(a, b);
		}
		while (*b)
			pa(a, b);
	}
}
