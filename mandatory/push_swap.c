/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 20:43:26 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/09 06:27:55 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_stacksize(*a);
	if (size == 2)
		sab(a, 'a');
	else if (size == 3)
		sort_3(a);
	else if (size <= 5)
		sort_5(a, b, size);
	else if (size <= 60)
		chuncker(a, b);
	else if (size <= 600)
		pivot(a, b);
	else
		ft_radix(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (check_input(argc, argv) || fill_stack(argc, argv, &a))
	{
		free_stack(a);
		free_stack(b);
		write(2, "Error\n", 6);
		return (1);
	}
	if (is_sorted(&a))
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	sort_stack(&a, &b);
	free_stack(a);
	free_stack(b);
}
