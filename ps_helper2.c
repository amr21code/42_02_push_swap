/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 06:29:38 by anruland          #+#    #+#             */
/*   Updated: 2022/05/15 14:50:26 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Frees the given list
 * @param kst [void *] Pointer to the given list
 */
void	ps_del(void *lst)
{
	free(lst);
}

void	ft_lstclear_ptr(t_list **lst)
{
	t_list	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = temp->next;
		free(temp);
	}
	*lst = NULL;
}

/**
 * Checks for the right amount of rotations needed for
 * rotating both at the same time
 * that is always the lowest # of rotations
 * @param arr [int *] 
 */
int	ps_smallest(int *arr)
{
	if (arr[1] < 0 && arr[2] < 0)
	{
		if (ps_abs(arr[1]) < ps_abs(arr[2]))
			return (arr[1]);
		else
			return (arr[2]);
	}
	else if (arr[1] >= 0 && arr[2] >= 0)
	{
		if (arr[1] < arr[2])
			return (arr[1]);
		else
			return (arr[2]);
	}
	return (0);
}

/**
 * Checks for the right amount of rotations needed
 * if one of a or b has 0 rotations return rotations
 * for a (arr[1])
 * if a needs less than or equal to the # of rotations
 * as b does return 0, else the difference
 * @param arr [int *] array with the solution
 * @param rotation [int *] array with the rotation
 */
int	ps_rest_a(int *arr, int *rotation)
{
	if (arr[1] == 0 || arr[2] == 0)
		return (arr[1]);
	else
		return (arr[1] - rotation[0]);
}

/**
 * Checks for the right amount of rotations needed
 * if one of a or b has 0 rotations return rotations
 * for b (arr[2])
 * if b needs less than or equal to the # of rotations
 * as a does return 0, else the difference
 * @param arr [int *] array with the solution
 * @param rotation [int *] array with the rotation
 */
int	ps_rest_b(int *arr, int *rotation)
{
	if (arr[1] == 0 || arr[2] == 0)
		return (arr[2]);
	else
		return (arr[2] - rotation[0]);
}
