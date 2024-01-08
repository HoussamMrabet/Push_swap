/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils-1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:12:54 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/07 23:57:17 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack **a)
{
	int		min;
	t_stack	*tmp;

	tmp = *a;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	get_min_index(t_stack **a)
{
	int		min;
	t_stack	*tmp;

	tmp = *a;
	min = tmp->index;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

int	get_max_index(t_stack **a)
{
	int		max;
	t_stack	*tmp;

	tmp = *a;
	max = tmp->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	get_max(t_stack **a)
{
	int		max;
	t_stack	*tmp;

	tmp = *a;
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	get_index(t_stack **a, int min)
{
	t_stack	*tmp;
	int		pos;

	tmp = *a;
	pos = 1;
	while (tmp)
	{
		if (tmp->index == min)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}
