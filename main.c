/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:04:29 by anruland          #+#    #+#             */
/*   Updated: 2022/04/03 20:02:50 by anruland         ###   ########.fr       */
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

// int	ps_index_max(int *seq, int len)
// {
// 	int	i;
// 	int	max;

// 	i = 0;
// 	max = INT_MIN;
// 	while (i < len)
// 	{
// 		if (seq[i] > max)
// 			max = seq[i];
// 	}
// 	return (max);
// }

int	*ps_get_sequence(int *list, int *sequence, int *length, int len)
{
	int	i;
	int	max;
	int	idx_max;
	int	*res;

	i = 0;
	idx_max = 0;
	max = INT_MIN;
	while (i < len)
	{
		ft_printf("i %d max %d length %d seq %d\n", i, max, length[i], idx_max);
		if (length[i] > max)
		{
			max = length[i];
			idx_max = i;
		}
		i++;
	}
	res = (int *)malloc(sizeof(int) * idx_max);
	while (--max >= 0)
	{
		res[max] = list[idx_max];
		idx_max = sequence[idx_max];
		ft_printf("seq %d res %d\n", idx_max, res[max]);
	}
	return (res);
}

int	*ps_find_lis(t_list *a, int len)
{
	int	i;
	int	j;
	int	*list;
	int	*length;
	int	*sequence;

	i = 1;
	ps_init_arrays(&list, &length, &sequence, a);
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (list[j] < list[i])
			{
				if ((length[j] + 1) >= length[i])
				{
					length[i] = length[j] + 1;
					sequence[i] = j;
				}
			}
			ft_printf("list[%d] = %d  *** list[%d] = %d\n", i, list[i], j, list[j]);
			ft_printf("length[%d] = %d\n", i, length[i]);
			ft_printf("sequence[%d] = %d\n\n", i, sequence[i]);
			j++;
		}
		ft_printf("***********************************************\n");
		i++;
	}
	i = 0;
	ft_printf("\n len");
	while (i < 12)
	{
		ft_printf(" %d", length[i]);
		i++;
	}
	i = 0;
	ft_printf("\n seq");
	while (i < 12)
	{
		ft_printf(" %d", sequence[i]);
		i++;
	}
	ft_printf("\n");
	return (ps_get_sequence(list, sequence, length, len));
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
		return (low_idx - size);
	else
		return (low_idx);
}

int	main(int ac, char **av)
{
	t_list	*a;
	// t_list	*b;
	t_list	*temp;
	int		lowest;
	int		*arr;
	int		i;

	i = 0;
	lowest = 0;
	a = NULL;
	// b = NULL;
	if (ac < 2 || ps_error_check(ac, av) || !ps_init_list(&a, ac, av))
		return (0);
	temp = ps_duplicate_lst(a);
	lowest = ps_find_lowest(temp);
	if (lowest > 0)
	{
		while (lowest--)
			ps_rotate(&a, 'a');
	}
	else if (lowest < 0)
	{
		while (lowest++)
			ps_rotate_reverse(&a, 'a');
	}
	free(temp);
	temp = ps_duplicate_lst(a);
	arr = ps_find_lis(temp, ft_lstsize(temp));
	while (i < 3)
	{
		ft_printf("*%d\n", arr[i]);
		i++;
	}
	ps_print_list(a, temp);
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