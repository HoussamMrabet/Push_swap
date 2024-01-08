/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 01:16:31 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/05 02:52:03 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	add_node(t_stack **a, int value)
{
	t_stack	*tmp;
	t_stack	*node;

	node = NULL;
	tmp = *a;
	if (!tmp)
	{
		node = (t_stack *)malloc(sizeof(t_stack));
		node->next = NULL;
		node->previous = NULL;
		node->value = value;
		*a = node;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		node = (t_stack *)malloc(sizeof(t_stack));
		node->next = NULL;
		node->previous = tmp;
		node->value = value;
		tmp->next = node;
	}
}

int	ft_stacksize(t_stack *head)
{
	int		i;
	t_stack	*tmp;

	tmp = head;
	i = 0;
	if (!tmp)
		return (i);
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_stack	*ft_stacklast(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	if (!tmp)
		return (tmp);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

long	ft_atol(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (*(str + i) && (*(str + i) == ' '
			|| (*(str + i) >= 9 && *(str + i) <= 13)))
		i++;
	if (*(str + i) == '+' || *(str + i) == '-')
	{
		if (*(str + i) == '-')
			sign = -sign;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		res = res * 10 + *(str + i) - 48;
		i++;
	}
	return (sign * res);
}
