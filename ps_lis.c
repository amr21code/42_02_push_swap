/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:00:39 by anruland          #+#    #+#             */
/*   Updated: 2022/05/15 17:07:13 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Uses the LIS struct to get the LIS and returns it
 * @param lis [t_liseq] Struct containing arrays with the following contents
 * @param lis.list [int *] - copy of stack a
 * @param lis.length [int *] - the length of the sequence to that point
 * @param lis.sequence [int *] - the index of the previous element in 
 * 								the sequence
 * @param lis.len [int] - the length of all arrays
 */
int	*ps_get_sequence(t_liseq lis, int i)
{
	int	max;
	int	idx_max;
	int	*res;

	idx_max = 0;
	max = INT_MIN;
	while (i < lis.len)
	{
		if (lis.length[i] > max)
		{
			max = lis.length[i];
			idx_max = i;
		}
		i++;
	}
	res = (int *)malloc(sizeof(int) * (max + 1));
	res[0] = ++max;
	while (--max > 0)
	{
		res[max] = lis.list[idx_max];
		idx_max = lis.sequence[idx_max];
	}
	ps_freelis(&lis);
	return (res);
}

/**
 * Main function to find the Largest Increasing Sequence (LIS)
 * Returns the array of the LIS
 * @param a [t_list] - Stack a
 */
int	*ps_find_lis(t_list *a)
{
	int		i;
	int		j;
	t_liseq	lis;

	i = 1;
	ps_init_arrays(&lis, a);
	ps_rotate_arr_list(&lis);
	while (i < lis.len)
	{
		j = 0;
		while (j < i)
		{
			if (lis.list[j] < lis.list[i])
			{
				if ((lis.length[j] + 1) >= lis.length[i])
				{
					lis.length[i] = lis.length[j] + 1;
					lis.sequence[i] = j;
				}
			}
			j++;
		}
		i++;
	}
	return (ps_get_sequence(lis, 0));
}

/**
 * Finds the lowest index
 * 
 * @param a [t_list] - Stack a
 */
int	ps_find_lowest(t_list *lst)
{
	int		low;
	int		i;
	int		low_idx;
	int		size;
	t_list	*head;

	head = lst;
	size = ft_lstsize(head);
	low = INT_MAX;
	i = 0;
	while (lst)
	{
		if (low > *(int *)lst->content)
		{
			low = *(int *)lst->content;
			low_idx = i;
		}
		lst = lst->next;
		i++;
	}
	if (low_idx > size / 2)
		return (low_idx - size);
	else
		return (low_idx);
}

/**
 * Check for LIS or not inside array
 * @param arr [int *] - Array with all non LIS elements
 * @param nb [int] - number to check
 */
int	ps_check_non_lis(int *arr, int nb)
{
	int		i;

	i = 1;
	while (i < arr[0])
	{
		if (nb == arr[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * Rotates and pushes all non LIS elements to b
 * @param arr [int *] - Array with all non LIS elements
 * @param a [t_list **] - Stack a
 * @param b [t_list **] - Stack a
 */
t_list	*ps_rm_non_lis(int *arr, t_list *a, t_list **b)
{
	while (ft_lstsize(a) > (arr[0] - 1))
	{
		if (!ps_check_non_lis(arr, *((int *)a->content)))
			ps_push(&a, b, 'a');
		else
			ps_rotate(&a, 'a', 0);
	}
	return (a);
}
