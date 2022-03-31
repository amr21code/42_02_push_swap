/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:56:19 by anruland          #+#    #+#             */
/*   Updated: 2022/03/31 17:57:00 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_print_list(t_list *a, t_list *b)
{
	while (a || b)
	{
		if (a)
		{
			ft_printf("%d\t\t\t", *((int *)a->content));
			a = a->next;
		}
		else
			ft_printf(" \t\t\t");
		if (b)
		{
			ft_printf("%d\n", *((int *)b->content));
			b = b->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("----\t\t\t----\n");
	ft_printf("a\t\t\tb\n\n");
}

int	ps_check_sort(t_list *head, char sort)
{
	t_list	*temp;

	while (head && head->next)
	{
		temp = head->next;
		if (sort == 'a')
		{
			if (*((int *)head->content) > *((int *)temp->content))
				return (0);
		}
		else if (sort == 'd')
		{
			if (*((int *)head->content) < *((int *)temp->content))
				return (0);
		}
		head = head->next;
	}
	return (1);
}
