/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:04:29 by anruland          #+#    #+#             */
/*   Updated: 2022/03/24 15:39:28 by anruland         ###   ########.fr       */
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

void	ps_init_list(t_list **a, int ac, char **av)
{
	int		i;
	t_list	*new;
	int		*content;

	content = (int *)malloc(sizeof(int));
	i = 1;
	while (i < ac)
	{
		*content = ft_atoi(av[i]);
		new = NULL;
		new = ft_lstnew(content);
		ft_lstadd_back(a, new);
		i++;
	}
	free(content);
}

int	main(int ac, char **av)
{
	t_list	*a;
	// t_list	*b;

	a = NULL;
	// b = NULL;
	if (ac < 2 || ps_error_check(ac, av))
		return (0);
	ps_init_list(&a, ac, av);
	ft_printf("%d - %s\n", ft_lstsize(a), a->content);
	if (a->content == (void *)-1)
		ft_printf("test erfolgreich");
	return (0);
}
