/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_precheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:55:17 by anruland          #+#    #+#             */
/*   Updated: 2022/05/15 11:05:47 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Checks if the string consists of only digits
 * @param str [char *] string to check for digits
  */
int	ft_isdigit_str(char *str)
{
	int	j;

	j = 0;
	if (str[0] == '-' || str[0] == '+')
		j++;
	while (str[j])
	{
		if (!ft_isdigit(str[j]))
			return (0);
		j++;
	}
	return (1);
}

/**
 * Checks if the given Arguments are digits
 * @param ac [int] count of arguments given
 * @param av [char **] arguments of push swap
 */
int	ps_check_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_isdigit_str(av[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * Checks the given arguments for invalid input
 * @param ac [int] count of arguments given
 * @param av [char **] arguments of push swap
 */
int	ps_error_check(int ac, char **av)
{
	int		i;
	int		j;
	long	atol;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		atol = ft_atol(av[i]);
		if (atol > INT_MAX || atol < INT_MIN || !ps_check_args(ac, av))
			ft_printerror("Error\n");
		while (j < ac)
		{
			if (ft_atol(av[j]) == atol)
				ft_printerror("Error\n");
			j++;
		}
		i++;
	}
	return (0);
}
