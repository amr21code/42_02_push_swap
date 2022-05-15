/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:11:02 by anruland          #+#    #+#             */
/*   Updated: 2022/05/15 10:51:12 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Pushes one number from src to dest.
 * @param src [t_list **] Source list to push from
 * @param dest [t_list **] Destination list to push to
 * @param srclst [char] determines the source list
*/
void	ps_push(t_list **src, t_list **dest, char srclst)
{
	t_list	*temp;

	if (ft_lstsize(*src) > 0)
	{
		temp = (*src)->next;
		if (*dest == NULL)
			(*src)->next = NULL;
		ft_lstadd_front(&(*dest), *src);
		*src = temp;
		if (srclst == 'b')
			ft_printf("pa\n");
		else if (srclst == 'a')
			ft_printf("pb\n");
	}
}
