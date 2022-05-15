/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:00:39 by anruland          #+#    #+#             */
/*   Updated: 2022/05/15 14:55:44 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ps_get_sequence(t_liseq lis)
{
	int	i;
	int	max;
	int	idx_max;
	int	*res;

	i = 0;
	idx_max = 0;
	max = INT_MIN;
	while (i < lis.len)
	{
		// ft_printf("length[%d] = %d, max %d, max_idx %d\n", i, (*length)[i], max, idx_max);
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
		// ft_printf("res[%d] = %d, idx_max %d")
	}
	// ft_printf("%d\n", res[0]);
	// ft_printf("%d\n", res[1]);
	// ft_printf("%d\n", res[2]);
	// ft_printf("%d\n", res[3]);
	free(lis.list);
	free(lis.sequence);
	free(lis.length);
	return (res);
}

int	*ps_find_lis(t_list *a)
{
	int		i;
	int		j;
	t_liseq	lis;

	i = 1;
	ps_init_arrays(&lis, a);
	ps_rotate_arr_list(&lis);
	// ft_printf("j = , length[%d] = %d, sequence = %d, list = %d \n", i, lis.length[i], lis.sequence[i], lis.list[i]);
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
	return (ps_get_sequence(lis));
}

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
		// ft_printf("low[%d] %d cont %d\n", low_idx, low, *(int *)lst->content);
		lst = lst->next;
		i++;
	}
	if (low_idx > size / 2)
		return (low_idx - size);
	else
		return (low_idx);
}

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
