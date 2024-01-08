/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions-0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 02:32:26 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/08 00:08:29 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sab(t_stack **head, char name)
{
	t_stack	*tmp;

	tmp = NULL;
	if (ft_stacksize(*head) > 1)
	{
		tmp = (*head)->next;
		if (tmp->next)
			tmp->next->previous = (*head);
		(*head)->next = tmp->next;
		(*head)->previous = tmp;
		tmp->next = (*head);
		tmp->previous = NULL;
		*(head) = tmp;
		if (name == 'a')
			ft_printf("sa\n");
		else if (name == 'b')
			ft_printf("sb\n");
	}
}

void	ss(t_stack **a, t_stack **b)
{
	sab(a, 's');
	sab(b, 's');
	ft_printf("ss\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = NULL;
	tmp_b = NULL;
	if (ft_stacksize(*b) > 0)
	{
		tmp_b = (*b)->next;
		tmp_a = (*a);
		(*b)->next = tmp_a;
		if (tmp_a)
			tmp_a->previous = *(a);
		if (tmp_b)
			tmp_b->previous = NULL;
		*a = *b;
		*b = tmp_b;
		ft_printf("pa\n");
	}
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = NULL;
	tmp_b = NULL;
	if (ft_stacksize(*a) > 0)
	{
		tmp_a = (*a)->next;
		tmp_b = (*b);
		(*a)->next = tmp_b;
		if (tmp_b)
			tmp_b->previous = *(a);
		if (tmp_a)
			tmp_a->previous = NULL;
		*b = *a;
		*a = tmp_a;
		ft_printf("pb\n");
	}
}
