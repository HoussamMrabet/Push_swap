/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 01:16:10 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/09 06:02:50 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_buff(char	**nbrs)
{
	int	i;

	i = 0;
	if (nbrs)
	{
		while (nbrs[i])
		{
			free(nbrs[i]);
			i++;
		}
		free(nbrs);
	}
}

int	check_dup(t_stack **a)
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
			if (tmp2->value == tmp1->value)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

int	check_argument(char **nbrs, t_stack **a)
{
	int	j;

	j = 0;
	if (!nbrs[j])
		return (1);
	while (nbrs[j])
	{
		if ((ft_strchr("-+", nbrs[j][0])
			&& !(nbrs[j][1] >= '0' && nbrs[j][1] <= '9'))
			|| strlen_nbr(nbrs[j]) >= 12 || ft_atol(nbrs[j]) > INT_MAX
			|| ft_atol(nbrs[j]) < INT_MIN)
			return (1);
		add_node(a, ft_atoi(nbrs[j]));
		j++;
	}
	free_buff(nbrs);
	return (0);
}

int	fill_stack(int argc, char **argv, t_stack **a)
{
	int		i;
	int		j;
	char	**nbrs;

	i = 1;
	j = 0;
	while (i < argc)
	{
		nbrs = ft_split(argv[i], 32);
		if (check_argument(nbrs, a))
			return (free_buff(nbrs), 1);
		j = 0;
		i++;
	}
	index_nodes(a);
	return (check_dup(a));
}

int	check_input(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	if (argc == 1)
		return (1);
	while (i < argc)
	{
		j = 0;
		if (!argv[i][0])
			return (1);
		while (argv[i][j])
		{
			if (!ft_strchr("-+0123456789 ", argv[i][j]))
				return (1);
			if (ft_strchr("-+", argv[i][j]) && ft_strchr("-+", argv[i][j + 1]))
				return (1);
			if (ft_strchr("0123456789", argv[i][j])
				&& (argv[i][j + 1] == '-' || argv[i][j + 1] == '+'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
