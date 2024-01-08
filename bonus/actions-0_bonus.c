/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions-0_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 02:32:26 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/08 00:07:39 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sab(t_stack **head)
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
	}
}

void	ss(t_stack **a, t_stack **b)
{
	sab(a);
	sab(b);
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
	}
}
