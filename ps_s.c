/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:37:17 by anruland          #+#    #+#             */
/*   Updated: 2022/03/28 15:28:14 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(t_list **head, char list)
{
	t_list	*temp;

	if (ft_lstsize(*head) > 1)
	{
		temp = *head;
		*head = (*head)->next;
		temp->next = (*head)->next;
		(*head)->next = temp;
		if (list == 'a')
			ft_printf("sa\n");
		else if (list == 'b')
			ft_printf("sb\n");
	}
}

void	ps_ss(t_list **a, t_list **b)
{
	ps_swap(a, ' ');
	ps_swap(b, ' ');
	ft_printf("ss\n");
}
