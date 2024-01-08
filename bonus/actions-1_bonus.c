/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions-1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 03:57:05 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/07 23:13:50 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrab(t_stack **ab)
{
	t_stack	*last;

	last = NULL;
	if (ft_stacksize(*ab) > 1)
	{
		last = ft_stacklast(*ab);
		last->previous->next = NULL;
		last->previous = NULL;
		last->next = *ab;
		(*ab)->previous = last;
		*ab = last;
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rrab(a);
	rrab(b);
}

void	rab(t_stack **ab)
{
	t_stack	*last;
	t_stack	*head;

	last = NULL;
	head = *ab;
	if (ft_stacksize(*ab) > 1)
	{
		last = ft_stacklast(*ab);
		*ab = head->next;
		head->next->previous = NULL;
		head->previous = last;
		head->next = NULL;
		last->next = head;
	}
}

void	rr(t_stack **a, t_stack **b)
{
	rab(a);
	rab(b);
}
