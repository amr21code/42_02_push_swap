/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:04:29 by anruland          #+#    #+#             */
/*   Updated: 2022/05/15 16:46:56 by anruland         ###   ########.fr       */
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
		arr = ps_find_lis(a);
		a = ps_rm_non_lis(arr, a, &b);
		ps_sort(&a, &b);
	}
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
 * Rotates both stacks to the right position of the
 * cheapest element and its postion in a
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
	rotation = ps_calc_rotation(solution);
	while (j < 3)
	{
		i = 0;
		rotas = ps_abs(rotation[j]);
		while (i < rotas)
		{
			ps_exec_smart_rotations(a, b, rotation, j);
			i++;
		}
		j++;
	}
	free(rotation);
}

/**
 * Finds the lowest number and rotates depending
 * on its position in the stack.
 * @param a [t_list **] Stack a
  */
void	ps_rotate_lowest(t_list **a)
{
	int		lowest;
	t_list	*temp;

	temp = ps_duplicate_lst(*a);
	lowest = ps_find_lowest(temp);
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
		if (ft_lstsize(*b) != 0)
		{
			ps_init_arr_bestelem(&acpy, &bcpy, *a, *b);
			solution = ps_find_cheapest_move(acpy, bcpy);
			ps_smart_rotate(solution, a, b);
			ps_push(b, a, 'b');
			free(solution);
			free(acpy);
			free(bcpy);
		}
		else
			ps_rotate_lowest(a);
	}
}
