/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:04:29 by anruland          #+#    #+#             */
/*   Updated: 2022/03/31 20:36:06 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_init_arrays(int **list, int **length, int **sequence, t_list *a)
{
	int	len;
	int	i;

	i = 0;
	len = ft_lstsize(a);
	*list = (int *)malloc(sizeof(int *) * len);
	*length = (int *)malloc(sizeof(int *) * len);
	*sequence = (int *)malloc(sizeof(int *) * len);
	while (a)
	{
		*list[i] = *((int *)a->content);
		*length[i] = 1;
		*sequence[i] = 0;
		a = a->next;
	}
}

int	*ps_find_lis(t_list *a, int len)
{
	int	i;
	int	j;
	int	*list;
	int	*length;
	int	*sequence;

	i = 1;
	j = 0;
	ps_init_arrays(&list, &length, &sequence, a);
	while (i < len)
	{
		while (j < i)
		{
			if (list[i] > list[j])
			{
				(length[i])++;
				sequence[i] = i;
			}
			j++;
		}
		i++;
	}
	return (0);
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
	printf("%d %d\n", low, *((int *)lst->content));
	while (lst)
	{
		if (low > *((int *)lst->content))
		{
			low = *((int *)lst->content);
			low_idx = i;
		}
		lst = lst->next;
		i++;
	}
	if (low_idx > size / 2)
		return (size - low_idx);
	else
		return (low_idx);
}

int	main(int ac, char **av)
{
	t_list	*a;
	// t_list	*b;
	t_list	*temp;
	int		lowest;

	lowest = 0;
	a = NULL;
	// b = NULL;
	if (ac < 2 || ps_error_check(ac, av) || !ps_init_list(&a, ac, av))
		return (0);
	temp = ps_duplicate_lst(a);
	lowest = ps_find_lowest(temp);
	ft_printf("%d\n", lowest);
	return (0);
}
		// ft_printf("%p\n", lst->next);

	// write(1, "T2st\n", 5);
	// while (!ps_check_sort(a, 'a') || ft_lstsize(b) > 0)
	// {
	// 	if (ft_lstsize(a) > 1
	// 		&& *((int *)a->content) > *((int *)(a->next)->content))
	// 		ps_swap(&a, 'a');
	// 	else
	// 		ps_push(&a, &b, 'a');
	// 	if (ft_lstsize(a) == 0 && ps_check_sort(b, 'd'))
	// 	{
	// 		while (b)
	// 			ps_push(&b, &a, 'b');
	// 	}
	// }
		// ps_print_list(a, b);
		// ps_push(&a, &b, 'a');
		// ps_push(&a, &b, 'a');
		// ps_ss(&a, &b);
		// ps_rotate(&a, 'a');
		// ps_rotate(&b, 'b');
		// ps_rr(&a, &b);
		// ps_rrr(&a, &b);
		// ps_rrr(&a, &b);
		// ps_print_list(a, 'a');
		// ps_print_list(b, 'b');
		// ft_printf("check %d\n", ps_check_sort(a, 'a'));