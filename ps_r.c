/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:24:39 by anruland          #+#    #+#             */
/*   Updated: 2022/05/15 17:10:28 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Rotates the given stack
 * The first element becomes the last one
 * If called by rr there will be no output of ra/rb
 * @param head [t_list **] Pointer to the list to rotate
 * @param list [char] determines the list to rotate
 * @param rr [int] determines the function call of rr
*/
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

/**
 * Rotates both lists
 * @param a [t_list **] List a
 * @param b [t_list **] List b
 */
void	ps_rr(t_list **a, t_list **b)
{
	ps_rotate(a, 'a', 1);
	ps_rotate(b, 'b', 1);
	ft_printf("rr\n");
}
