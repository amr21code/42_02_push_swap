/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:56:19 by anruland          #+#    #+#             */
/*   Updated: 2022/05/15 10:36:53 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_print_list(t_list *a, t_list *b)
{
	while (a || b)
	{
		if (a)
		{
			ft_printf("%d (%d)\t\t\t", *((int *)a->content), a->idx);
			a = a->next;
		}
		else
			ft_printf("     \t\t\t");
		if (b)
		{
			ft_printf("%d (%d)\n", *((int *)b->content), b->idx);
			b = b->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("----\t\t\t----\n");
	ft_printf("a\t\t\tb\n\n");
}

/**
 * Check if head is sorted.
 * @param head [t_list *] Pointer to the list
 * @param sort [char] determines list 'a' or list 'b'
 */
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
