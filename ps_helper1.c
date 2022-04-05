/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:04:58 by anruland          #+#    #+#             */
/*   Updated: 2022/04/05 20:05:05 by anruland         ###   ########.fr       */
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
