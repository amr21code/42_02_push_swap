/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:47:43 by anruland          #+#    #+#             */
/*   Updated: 2022/03/28 16:48:23 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rotate_reverse(t_list **head, char list)
{
	t_list	*temp;

	if (ft_lstsize(*head) > 1)
	{
		temp = *head;
		ft_lstadd_front(&(*head), *head);
		*head = temp->next;
		temp->next = NULL;
		if (list == 'a')
			ft_printf("rra\n");
		else if (list == 'b')
			ft_printf("rrb\n");
	}
}

void	ps_rrr(t_list **a, t_list **b)
{
	ps_rotate(a, 'a');
	ps_rotate(b, 'b');
	ft_printf("rrr\n");
}
