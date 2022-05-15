/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:57 by anruland          #+#    #+#             */
/*   Updated: 2022/05/15 17:05:45 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Destroys and frees the lists and the LIS array
 * @param a [t_list **] Stack a
 * @param b [t_list **] Stack b
 * @param arr [int *] LIS array
 */
void	ps_destroy(t_list **a, t_list **b, int *arr)
{
	ft_lstclear(a, ps_del);
	ft_lstclear(b, ps_del);
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
}

/**
 * Frees the LIS struct
 * @param lis [t_liseq *] LIS struct
 */
void	ps_freelis(t_liseq *lis)
{
	free(lis->list);
	free(lis->sequence);
	free(lis->length);
}

/**
 * Executing the smart rotation
 * @param a [t_list **] Stack a
 * @param b [t_list **] Stack b
 * @param rotation [int *] array of rotations
 * @param j [int] counting variable
 */
void	ps_exec_smart_rotations(t_list **a, t_list **b, int *rotation, int j)
{
	if (j == 0 && rotation[j] < 0)
		ps_rrr(a, b);
	else if (j == 0)
		ps_rr(a, b);
	else if (j == 1 && rotation[j] < 0)
		ps_rotate_reverse(a, 'a', 0);
	else if (j == 1)
		ps_rotate(a, 'a', 0);
	else if (j == 2 && rotation[j] < 0)
		ps_rotate_reverse(b, 'b', 0);
	else if (j == 2)
		ps_rotate(b, 'b', 0);
}
