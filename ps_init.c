/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:57:29 by anruland          #+#    #+#             */
/*   Updated: 2022/04/09 18:10:00 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Functions for initialisation */

#include "push_swap.h"

/* Initialize list from arguments */

int	ps_init_list(t_list **a, int ac, char **av)
{
	int		i;
	t_list	*new;
	int		*content;

	i = 1;
	while (i < ac)
	{
		content = (int *)malloc(sizeof(int));
		*content = ft_atoi(av[i]);
		new = NULL;
		new = ft_lstnew(content);
		ft_lstadd_back(a, new);
		i++;
	}
	// ft_printf("a2 = %d\n", *((int *)(*a)->content));
	// ft_printf("a = %d\n", *(int *)new->content);
	if (ps_check_sort(*a, 'a'))
		return (0);
	return (1);
}
