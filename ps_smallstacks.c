/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_smallstacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:48:02 by anruland          #+#    #+#             */
/*   Updated: 2022/05/15 10:49:42 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sort if the list only contains 3 or less elements.
 * @param a [t_list **] address of stack a
 * @param b [t_list **] address of stack b
*/
void	ps_sort_small(t_list **a, t_list **b)
{
	while (!ps_check_sort(*a, 'a') || ft_lstsize(*b) != 0)
	{
		if (ft_lstsize(*a) <= 3 && !ps_check_sort(*a, 'a'))
			ps_sort_lt3(a, b);
		else
			ps_sort_lt5(a, b);
	}
}

/**
 * Sort if the list only contains 3 or less elements.
 * @param a [t_list **] address of stack a
 * @param b [t_list **] address of stack b
*/
void	ps_sort_lt3(t_list **a, t_list **b)
{
	if ((*a)->idx < (*a)->next->idx)
	{
		ps_rotate_reverse(a, 'a', 0);
		if (!ps_check_sort(*a, 'a'))
			ps_swap(a, 'a', 0);
	}
	else
	{
		ps_swap(a, 'a', 0);
		if (!ps_check_sort(*a, 'a'))
			ps_sort_lt3(a, b);
	}
}

/**
 * Sort if the list only contains 5 or less elements.
 * @param a [t_list **] address of stack a
 * @param b [t_list **] address of stack b
*/
void	ps_sort_lt5(t_list **a, t_list **b)
{
	if (!ps_check_sort(*a, 'a'))
	{
		if ((*a)->idx == 1 || (*a)->idx == 2)
			ps_push(a, b, 'a');
		else if (ft_lstlast(*a)->idx == 1 || ft_lstlast(*a)->idx == 2)
		{
			ps_rotate_reverse(a, 'a', 0);
			ps_push(a, b, 'a');
		}
		ps_rotate(a, 'a', 0);
	}
	else
	{
		if ((*b)->next && (*b)->idx < (*b)->next->idx)
			ps_swap(b, 'b', 0);
		while (*b)
			ps_push(b, a, 'b');
		if (!ps_check_sort(*a, 'a'))
			ps_swap(a, 'a', 0);
	}
}
