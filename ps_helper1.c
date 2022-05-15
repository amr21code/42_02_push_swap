/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:04:58 by anruland          #+#    #+#             */
/*   Updated: 2022/05/15 16:48:05 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Finds the index with the maximum number in the given array
 * and returns the maximum index.
 * @param lis [t_liseq] Struct containing arrays with the following contents
 * @param lis.list [int *] - copy of stack a
 * @param lis.length [int *] - the length of the sequence to that point
 * @param lis.sequence [int *] - the index of the previous element in 
 * 								the sequence
 * @param lis.len [int] - the length of all arrays
 */
int	ps_find_lowest_idx(t_liseq lis)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = lis.list[i];
	while (i < lis.len)
	{
		if (tmp > lis.list[i])
		{
			tmp = lis.list[i];
			j = i;
		}
		i++;
	}
	return (j);
}

/**
 * Rotates the lis.list array to have the lowest element at index 0
 * @param lis [t_liseq] Struct containing arrays with the following contents
 * @param lis.list [int *] - copy of stack a
 * @param lis.length [int *] - the length of the sequence to that point
 * @param lis.sequence [int *] - the index of the previous element in 
 * 								the sequence
 * @param lis.len [int] - the length of all arrays
 */
void	ps_rotate_arr_list(t_liseq *lis)
{
	int	i;
	int	j;
	int	tmp;

	tmp = 0;
	i = ps_find_lowest_idx(*lis);
	while (i)
	{
		j = 0;
		tmp = (*lis).list[j];
		while (j < (*lis).len)
		{
			if (j == (*lis).len -1)
				(*lis).list[j] = tmp;
			else
				(*lis).list[j] = (*lis).list[j + 1];
			j++;
		}
		i--;
	}
}

t_list	*ps_duplicate_lst(t_list *lst)
{
	t_list	*new;

	new = NULL;
	while (lst)
	{
		ft_lstadd_back(&new, ft_lstnew(lst->content));
		lst = lst->next;
	}
	return (new);
}

/**
 * Finds the index with the maximum number in the given array
 * and returns the maximum index.
 * @param arr [int *] Array to look for maximum
 * @param b [int *] Array copy of stack b
 * arr[0] = length of array
 */
int	ps_find_max(int *arr)
{
	int	i;
	int	max_idx;

	max_idx = 1;
	i = 1;
	while (i <= arr[0])
	{
		if (arr[max_idx] < arr[i])
			max_idx = i;
		i++;
	}
	return (max_idx);
}

int	ps_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}
