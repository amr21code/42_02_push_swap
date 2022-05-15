/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:57 by anruland          #+#    #+#             */
/*   Updated: 2022/05/13 16:04:41 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_destroy(t_list **a, t_list **b, int *arr)
{
	ft_lstclear(a, ps_del);
	ft_lstclear(b, ps_del);
	if (arr)
		free(arr);
}
