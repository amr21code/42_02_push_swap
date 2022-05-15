/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:37:17 by anruland          #+#    #+#             */
/*   Updated: 2022/05/15 10:47:50 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Swaps the first two elements of the given list
 * If called by ss there will be no output of sa/sb
 * @param head [t_list **] The list to swap
 * @param list [char] Determines the list
 * @param ss [int] 1 if the function gets called by ss
 */
void	ps_swap(t_list **head, char list, int ss)
{
	t_list	*temp;

	if (ft_lstsize(*head) > 1)
	{
		temp = *head;
		*head = (*head)->next;
		temp->next = (*head)->next;
		(*head)->next = temp;
		if (list == 'a' && !ss)
			ft_printf("sa\n");
		else if (list == 'b' && !ss)
			ft_printf("sb\n");
	}
}

void	ps_ss(t_list **a, t_list **b)
{
	ps_swap(a, ' ', 1);
	ps_swap(b, ' ', 1);
	ft_printf("ss\n");
}
