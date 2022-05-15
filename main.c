/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:04:29 by anruland          #+#    #+#             */
/*   Updated: 2022/05/15 15:16:14 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rotate_lowest(t_list **a);
void	ps_smart_rotate(int *solution, t_list **a, t_list **b);
int		*ps_calc_rotation(int *solution);
void	ps_sort(t_list **a, t_list **b);

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		*arr;

	a = NULL;
	b = NULL;
	if (ac < 2 || ps_error_check(ac, av) || !ps_init_list(&a, ac, av))
	{
		ft_lstclear(&a, ps_del);
		return (0);
	}
	else if (ac < 7)
		ps_sort_small(&a, &b);
	else
	{
		// ps_print_list(a, b);
		arr = ps_find_lis(a);
		a = ps_rm_non_lis(arr, a, &b);
		// ps_print_list(a, b);
		ps_sort(&a, &b);
	}
	// ps_print_list(a, b);
	ps_destroy(&a, &b, arr);
	return (0);
}

/**
 * Calculates the rotations for the solution
 * 0 - # of rotations for a and b at the same time
 * 1 - # of rotations for a
 * 2 - # of rotations for b
 * @param solution [int *] Array for solution
  */
int	*ps_calc_rotation(int *solution)
{
	int	*rotation;

	rotation = (int *)malloc(sizeof(int) * 3);
	if ((solution[1] * solution[2]) <= 0)
	{
		rotation[0] = 0;
		rotation[1] = ps_rest_a(solution, rotation);
		rotation[2] = ps_rest_b(solution, rotation);
	}
	else
	{
		rotation[0] = ps_smallest(solution);
		rotation[1] = ps_rest_a(solution, rotation);
		rotation[2] = ps_rest_b(solution, rotation);
	}
	return (rotation);
}

/**
 * Rotates
 * 
 * @param solution [int *] the cheapest move
 * @param a [t_list **] Stack a
 * @param b [t_list **] Stack b
 */
void	ps_smart_rotate(int *solution, t_list **a, t_list **b)
{
	int	i;
	int	*rotation;
	int	j;
	int	rotas;

	j = 0;
	// ft_printf("solution nb = %d, a = %d, b = %d\n", solution[0], solution[1], solution[2]);
	rotation = ps_calc_rotation(solution);
	// ft_printf("solution nb = %d, a = %d, b = %d\n", solution[0], solution[1], solution[2]);
	// ft_printf("rotation both = %d, a = %d, b = %d\n", rotation[0], rotation[1], rotation[2]);
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
				ps_rotate_reverse(a, 'a', 0);
			else if (j == 1)
				ps_rotate(a, 'a', 0);
			else if (j == 2 && rotation[j] < 0)
				ps_rotate_reverse(b, 'b', 0);
			else if (j == 2)
				ps_rotate(b, 'b', 0);
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
	// ft_printf("lowest %d", lowest);
	if (lowest > 0)
	{
		while (lowest--)
			ps_rotate(a, 'a', 0);
	}
	else if (lowest < 0)
	{
		while (lowest++)
			ps_rotate_reverse(a, 'a', 0);
	}
	// ft_printf("t %p\n", &temp);
	// ps_print_list(*a, temp);
	ft_lstclear_ptr(&temp);
}

/**
 * Main Sorting with the LIS algorithm
 * Search through temp arrays for the cheapest move and smart rotate
 * to push to the right position
 * @param a [t_list **] Stack a
 * @param b [t_list **] Stack b
 */
void	ps_sort(t_list **a, t_list **b)
{
	int	*acpy;
	int	*bcpy;
	int	*solution;

	while (!ps_check_sort(*a, 'a') || ft_lstsize(*b) != 0)
	{
		// ps_print_list(*a, *b);
		if (ft_lstsize(*b) != 0)
		{
			ps_init_arr_bestelem(&acpy, &bcpy, *a, *b);
			solution = ps_find_cheapest_move(acpy, bcpy);
			ps_smart_rotate(solution, a, b);
			ps_push(b, a, 'b');
			// ps_print_list(*a, *b);
			free(solution);
			free(acpy);
			free(bcpy);
		}
		else
			ps_rotate_lowest(a);
	}
}

	// ft_printf("a2 = %d\n", *((int *)(*a)->content));
	// ft_printf("a = %d\n", *(int *)a->content);
	// ft_printf("a2 = %d\n", *((int *)(*a)->content));
	// ft_printf("a = %d\n", *(int *)a->content);
	// ft_printf("a %p\n", a);
	// ps_rotate_lowest(&a);
	// temp = ps_duplicate_lst(a);
