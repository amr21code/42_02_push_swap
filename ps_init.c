/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:57:29 by anruland          #+#    #+#             */
/*   Updated: 2022/05/15 12:53:41 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Functions for initialisation */

#include "push_swap.h"

/**
 * Initialize the list at start with an index and
 * check if its already sorted.
 * @param a [t_list **] Nullpointer list from main
 * @param ac [int] count of arguments given
 * @param av [char **] arguments of push swap
 */
int	ps_init_list(t_list **a, int ac, char **av)
{
	int		i;
	t_list	*new;
	int		*content;

	i = 1;
	while (i < ac)
	{
		content = (int *)malloc(sizeof(int));
		*content = ft_atoi(av[i]);
		new = NULL;
		new = ft_lstnew(content);
		new->idx = 0;
		ft_lstadd_back(a, new);
		i++;
	}
	if (ps_check_sort(*a, 'a'))
		return (0);
	ps_update_idx(*a);
	return (1);
}

/**
 * Updates the list element 'index'. 
 * The smallest element gets index 1 increasing to
 * index n (of the nth element)
 * @param a [t_list *] List a
 */
void	ps_update_idx(t_list *a)
{
	int		len;
	long	i;
	t_list	*tmp;
	t_list	*smaller;

	smaller = NULL;
	i = 1;
	len = ft_lstsize(a);
	while (i <= len)
	{
		tmp = a;
		smaller = tmp;
		while (smaller && smaller->idx)
			smaller = smaller->next;
		while (tmp)
		{
			if (!tmp->idx && *(int *)tmp->content < *(int *)smaller->content)
				smaller = tmp;
			tmp = tmp->next;
		}
		smaller->idx = i;
		i++;
	}
}

void	ps_init_arrays(t_liseq *lis, t_list *a)
{
	int	i;

	i = 0;
	(*lis).len = ft_lstsize(a);
	(*lis).list = malloc(sizeof(int) * (*lis).len);
	(*lis).length = malloc(sizeof(int) * (*lis).len);
	(*lis).sequence = malloc(sizeof(int) * (*lis).len);
	while (a)
	{
		// ft_printf("c = %d\n", a->idx);
		((*lis).list)[i] = *(int *)a->content;
		((*lis).length)[i] = 1;
		((*lis).sequence)[i] = 0;
		// ft_printf("length[%d] = %d, sequence = %d, list = %d c = %d\n", i, (*length)[i], (*sequence)[i], (*list)[i], *(int *)a->content);
		a = a->next;
		i++;
	}
}

/**
 * Initialization of arrays to calculate the best element to push back next
 * @param acpy [int **] Copy of stack a with indices
 * @param bcpy [int **] Copy of stack b with indices
 * @param a [t_list *] Stack a
 * @param b [t_list *] Stack b
 * acpy[0] / bcpy[0] = length of the array
 */
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
		(*acpy)[i] = a->idx;
		a = a->next;
		i++;
	}
	i = 1;
	len = ft_lstsize(b);
	*bcpy = malloc(sizeof(int) * (len + 1));
	(*bcpy)[0] = len;
	while (b)
	{
		(*bcpy)[i] = b->idx;
		b = b->next;
		i++;
	}
}
