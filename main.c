/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:04:29 by anruland          #+#    #+#             */
/*   Updated: 2022/04/05 20:05:21 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list	*temp;
	int		lowest;
	int		*arr;

	lowest = 0;
	a = NULL;
	b = NULL;
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
	a = ps_rm_non_lis(arr, a, &b);
	ps_print_list(a, b);
	return (0);
}

	// int i;
	// i = 0;
	// while (i < arr[0])
	// {
	// 	ft_printf("arr[%d] = %d\n", i, arr[i]);
	// 	i++;
	// }