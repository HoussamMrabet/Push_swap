/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions-1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 03:57:05 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/05 00:00:03 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrab(t_stack **ab, char name)
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
		if (name == 'a')
			ft_printf("rra\n");
		else if (name == 'b')
			ft_printf("rrb\n");
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rrab(a, 's');
	rrab(b, 's');
	ft_printf("rrr\n");
}

void	rab(t_stack **ab, char name)
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
		if (name == 'a')
			ft_printf("ra\n");
		else if (name == 'b')
			ft_printf("rb\n");
	}
}

void	rr(t_stack **a, t_stack **b)
{
	rab(a, 's');
	rab(b, 's');
	ft_printf("rr\n");
}
