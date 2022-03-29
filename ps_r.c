/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:24:39 by anruland          #+#    #+#             */
/*   Updated: 2022/03/28 15:45:35 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rotate(t_list **head, char list)
{
	t_list	*temp;

	if (ft_lstsize(*head) > 1)
	{
		temp = *head;
		ft_lstadd_back(&(*head), *head);
		*head = temp->next;
		temp->next = NULL;
		if (list == 'a')
			ft_printf("ra\n");
		else if (list == 'b')
			ft_printf("rb\n");
	}
}

void	ps_rr(t_list **a, t_list **b)
{
	ps_rotate(a, 'a');
	ps_rotate(b, 'b');
	ft_printf("rr\n");
}
