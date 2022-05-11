/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 06:29:38 by anruland          #+#    #+#             */
/*   Updated: 2022/05/07 06:30:38 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ps_smallest(int *arr)
{
	if (arr[1] < arr[2])
		return (arr[1]);
	else
		return (arr[2]);
}

int	ps_rest_a(int *arr)
{
	if (arr[1] == 0 || arr[2] == 0)
		return (arr[1]);
	else if (arr[1] <= arr[2])
		return (0);
	else
		return (arr[1] - arr[2]);
}

int	ps_rest_b(int *arr)
{
	if (arr[1] == 0 || arr[2] == 0)
		return (arr[2]);
	else if (arr[1] >= arr[2])
		return (0);
	else
		return (arr[2] - arr[1]);
}
