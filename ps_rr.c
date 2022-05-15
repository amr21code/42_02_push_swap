/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:47:43 by anruland          #+#    #+#             */
/*   Updated: 2022/05/15 11:51:36 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sets the new last element.
 * @param lst [t_list *] pointer to the list
 * @param old [t_list **] old last element
 */
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

/**
 * Reverse Rotates the list.
 * The last element becomes the first.
 * If called by rrr there will be no output of rra/rrb
 * @param head [t_list **] List to rotate
 * @param list [char] determines the given list
 * @param rrr [int] 1 if the function gets called by rrr
 */
void	ps_rotate_reverse(t_list **head, char list, int rrr)
{
	t_list	*temp;

	if (ft_lstsize(*head) > 1)
	{
		temp = ft_lstlast(*head);
		temp->next = *head;
		ft_lstadd_front(&(*head), temp);
		ft_lstsetnewlast(*head, &temp);
		if (list == 'a' && !rrr)
			ft_printf("rra\n");
		else if (list == 'b' && !rrr)
			ft_printf("rrb\n");
	}
}

/**
 * Reverse rotates both lists
 * @param a [t_list **] List a
 * @param b [t_list **] List b
 */
void	ps_rrr(t_list **a, t_list **b)
{
	ps_rotate_reverse(a, 'a', 1);
	ps_rotate_reverse(b, 'b', 1);
	ft_printf("rrr\n");
}
