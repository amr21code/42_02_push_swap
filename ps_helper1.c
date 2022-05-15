/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:04:58 by anruland          #+#    #+#             */
/*   Updated: 2022/05/15 12:55:52 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ps_rotate_arr_list(t_liseq *lis)
{
	int	i;
	int	j;
	int	tmp;

	tmp = 0;
	i = ps_find_lowest_idx(*lis);
	// ft_printf("i %d\n", i);
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
			// ft_printf("i = %d, list[0] = %d list[1] = %d list[2] = %d list[3] = %d\n", i, (*lis).list[0], (*lis).list[1], (*lis).list[2], (*lis).list[3]);
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
