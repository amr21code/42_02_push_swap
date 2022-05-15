/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:24:39 by anruland          #+#    #+#             */
/*   Updated: 2022/05/15 09:08:44 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rotate(t_list **head, char list, int rr)
{
	t_list	*temp;

	if (ft_lstsize(*head) > 1)
	{
		temp = *head;
		ft_lstadd_back(&(*head), temp);
		*head = temp->next;
		temp->next = NULL;
		if (list == 'a' && !rr)
			ft_printf("ra\n");
		else if (list == 'b' && !rr)
			ft_printf("rb\n");
	}
}

void	ps_rr(t_list **a, t_list **b)
{
	ps_rotate(a, 'a', 1);
	ps_rotate(b, 'b', 1);
	ft_printf("rr\n");
}
