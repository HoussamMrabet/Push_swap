/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 01:16:10 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/05 02:51:35 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_buff(char	**nbrs, int start)
{
	while (nbrs[start])
	{
		free(nbrs[start]);
		start++;
	}
	free(nbrs);
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
			{
				free_stack(*a);
				return (1);
			}
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
	{
		free_buff(nbrs, j);
		free_stack(*a);
		return (1);
	}
	while (nbrs[j])
	{
		if ((ft_strchr("-+", nbrs[j][0])
			&& !(nbrs[j][1] >= '0' && nbrs[j][1] <= '9'))
			|| (ft_strlen(nbrs[j]) >= 12) || ft_atol(nbrs[j]) > INT_MAX
			|| ft_atol(nbrs[j]) < INT_MIN)
			return (free_buff(nbrs, j), free_stack(*a), 1);
		add_node(a, ft_atoi(nbrs[j]));
		free(nbrs[j]);
		j++;
	}
	free(nbrs);
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
			return (1);
		j = 0;
		i++;
	}
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
