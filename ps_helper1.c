/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:04:58 by anruland          #+#    #+#             */
/*   Updated: 2022/04/06 19:25:16 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_init_arrays(int **list, int **length, int **sequence, t_list *a)
{
	int	len;
	int	i;

	i = 0;
	len = ft_lstsize(a);
	*list = malloc(sizeof(int) * len);
	*length = malloc(sizeof(int) * len);
	*sequence = malloc(sizeof(int) * len);
	while (a)
	{
		(*list)[i] = *((int *)a->content);
		(*length)[i] = 1;
		(*sequence)[i] = 0;
		a = a->next;
		i++;
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

void	ps_init_arr_bestelem(int **acpy, int **bcpy, t_list *a, t_list *b)
{
	int	len;
	int	i;

	i = 1;
	len = ft_lstsize(a);
	*acpy = malloc(sizeof(int) * (len + 1));
	(*acpy)[0] = len;
	while (a)
	{
		(*acpy)[i] = *((int *)a->content);
		a = a->next;
		i++;
	}
	i = 1;
	len = ft_lstsize(b);
	*bcpy = malloc(sizeof(int) * (len + 1));
	(*bcpy)[0] = len;
	while (b)
	{
		(*bcpy)[i] = *((int *)b->content);
		b = b->next;
		i++;
	}
}

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