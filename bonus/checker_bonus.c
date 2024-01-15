/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 20:43:26 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/10 01:02:00 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	free_stack(*a);
	*a = NULL;
	return (1);
}

int	make_action(char *str, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(str, "sa\n", 4))
		sab(a);
	else if (!ft_strncmp(str, "sb\n", 4))
		sab(b);
	else if (!ft_strncmp(str, "ss\n", 4))
		ss(a, b);
	else if (!ft_strncmp(str, "pa\n", 4))
		pa(a, b);
	else if (!ft_strncmp(str, "pb\n", 4))
		pb(a, b);
	else if (!ft_strncmp(str, "ra\n", 4))
		rab(a);
	else if (!ft_strncmp(str, "rb\n", 4))
		rab(b);
	else if (!ft_strncmp(str, "rr\n", 4))
		rr(a, b);
	else if (!ft_strncmp(str, "rra\n", 5))
		rrab(a);
	else if (!ft_strncmp(str, "rrb\n", 5))
		rrab(b);
	else if (!ft_strncmp(str, "rrr\n", 5))
		rrr(a, b);
	else
		return (1);
	return (0);
}

void	get_answers(t_stack **a, t_stack **b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (make_action(str, a, b))
		{
			free_stack(*a);
			free_stack(*b);
			free(str);
			str = NULL;
			write(2, "Error\n", 6);
			exit(1);
		}
		free(str);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (check_input(argc, argv))
	{
		ft_putstr_fd("Error", 2);
		return (1);
	}
	if (fill_stack(argc, argv, &a))
	{
		ft_putstr_fd("Error", 2);
		return (1);
	}
	get_answers(&a, &b);
	if (is_sorted(&a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(a);
	free_stack(b);
}
