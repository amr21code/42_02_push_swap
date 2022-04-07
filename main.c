/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:04:29 by anruland          #+#    #+#             */
/*   Updated: 2022/04/07 19:32:58 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	*ps_calc_rotation(int *solution)
{
	int	*rotation;

	rotation = (int *)malloc(sizeof(int) * 3);
	if ((solution[1] * solution[2]) <= 0)
	{
		rotation[0] = 0;
		rotation[1] = ps_rest_a(solution);
		rotation[2] = ps_rest_b(solution);
	}
	else
	{
		rotation[0] = ps_smallest(solution);
		rotation[1] = ps_rest_a(solution);
		rotation[2] = ps_rest_b(solution);
	}
	return (rotation);
}

void	ps_smart_rotate(int *solution, t_list **a, t_list **b)
{
	int	i;
	int	*rotation;
	int	j;
	int	rotas;

	j = 0;
	rotation = ps_calc_rotation(solution);
	// ft_printf("rotation 0 = %d, 1 = %d, 2 = %d\n", rotation[0], rotation[1], rotation[2]);
	while (j < 3)
	{
		i = 0;
		rotas = ps_abs(rotation[j]);
		while (i < rotas)
		{
			if (j == 0 && rotation[j] < 0)
				ps_rrr(a, b);
			else if (j == 0)
				ps_rr(a, b);
			else if (j == 1 && rotation[j] < 0)
				ps_rotate_reverse(a, 'a');
			else if (j == 1)
				ps_rotate(a, 'a');
			else if (j == 2 && rotation[j] < 0)
				ps_rotate_reverse(b, 'b');
			else if (j == 2)
				ps_rotate(b, 'b');
			i++;
		}
		j++;
	}
	free(rotation);
}

void	ps_rotate_lowest(t_list **a)
{
	int		lowest;
	t_list	*temp;

	temp = ps_duplicate_lst(*a);
	lowest = ps_find_lowest(temp);
	if (lowest > 0)
	{
		while (lowest--)
			ps_rotate(a, 'a');
	}
	else if (lowest < 0)
	{
		while (lowest++)
			ps_rotate_reverse(a, 'a');
	}
	free(temp);
}

void	ps_sort(t_list **a, t_list **b)
{
	int	*acpy;
	int	*bcpy;
	int	*solution;

	while (!ps_check_sort(*a, 'a') || ft_lstsize(*b) != 0)
	{
		if (ft_lstsize(*b) != 0)
		{
			ps_init_arr_bestelem(&acpy, &bcpy, *a, *b);
			solution = ps_find_cheapest_move(acpy, bcpy);
			// ft_printf("final solution 0 = %d, 1 = %d, 2 = %d\n", solution[0], solution[1], solution[2]);
			ps_smart_rotate(solution, a, b);
			ps_push(b, a, 'b');
			// ps_print_list(*a, *b);
			free(solution);
		}
		else
			ps_rotate_lowest(a);
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list	*temp;
	int		*arr;

	a = NULL;
	b = NULL;
	if (ac < 2 || ps_error_check(ac, av) || !ps_init_list(&a, ac, av))
		return (0);
	ps_rotate_lowest(&a);
	temp = ps_duplicate_lst(a);
	arr = ps_find_lis(temp, ft_lstsize(temp));
	a = ps_rm_non_lis(arr, a, &b);
	// ps_print_list(a, b);
	ps_sort(&a, &b);
	// ps_print_list(a, b);
	return (0);
}
