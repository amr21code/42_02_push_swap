/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_precheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:55:17 by anruland          #+#    #+#             */
/*   Updated: 2022/03/31 20:05:53 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit_str(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == '-' || str[j] == '+')
			j++;
		if (!ft_isdigit(str[j]))
			return (1);
		j++;
	}
	return (0);
}

int	ps_error_check(int ac, char **av)
{
	int		i;
	int		j;
	long	atol;

	i = 1;
	while (i < ac)
	{
		j = i - 1;
		atol = ft_atol(av[i]);
		while (j >= 0)
		{
			if (atol > INT_MAX || atol < INT_MIN
				|| ft_isdigit_str(av[i]) || ft_atol(av[j]) == atol)
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			}
			j--;
		}
		i++;
	}
	return (0);
}
