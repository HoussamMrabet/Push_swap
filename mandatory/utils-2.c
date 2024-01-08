/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils-2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:57:41 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/08 19:09:32 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_next_min(t_stack **a, int min)
{
	int		next_min;
	t_stack	*tmp;

	tmp = *a;
	next_min = min;
	while (tmp)
	{
		if (tmp->value > next_min)
		{
			next_min = tmp->value;
			break ;
		}
		tmp = tmp->next;
	}
	tmp = *a;
	while (tmp)
	{
		if (tmp->value > min && tmp->value < next_min)
			next_min = tmp->value;
		tmp = tmp->next;
	}
	return (next_min);
}

void	index_nodes(t_stack **a)
{
	int		min;
	t_stack	*tmp;
	int		size;
	int		i;

	tmp = NULL;
	size = ft_stacksize(*a);
	i = 0;
	while (i < size)
	{
		if (i)
			min = get_next_min(a, min);
		else
			min = get_min(a);
		tmp = *a;
		while (tmp)
		{
			if (tmp->value == min)
				tmp->index = i;
			tmp = tmp->next;
		}
		i++;
	}
}

int	get_value_index(t_stack **a, int min)
{
	t_stack	*tmp;
	int		pos;

	tmp = *a;
	pos = 1;
	while (tmp)
	{
		if (tmp->value == min)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

int	strlen_nbr(char *nbr)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (nbr[i] && (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13)))
		i++;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		i++;
		len++;
	}
	while (nbr[i] && nbr[i] == '0')
		i++;
	while (nbr[i] && (nbr[i] >= '0' && nbr[i] <= '9'))
	{
		len++;
		i++;
	}
	return (len);
}
