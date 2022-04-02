/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:47:43 by anruland          #+#    #+#             */
/*   Updated: 2022/04/02 18:23:08 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstsetnewlast(t_list *lst, t_list **old)
{
	while (lst)
	{
		if (lst->next == *old)
		{
			lst->next = NULL;
			return ;
		}
		lst = lst->next;
	}
}

void	ps_rotate_reverse(t_list **head, char list)
{
	t_list	*temp;

	if (ft_lstsize(*head) > 1)
	{
		temp = ft_lstlast(*head);
		temp->next = *head;
		ft_lstadd_front(&(*head), temp);
		ft_lstsetnewlast(*head, &temp);
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
