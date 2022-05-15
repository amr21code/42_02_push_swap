/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cheapest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:25:59 by anruland          #+#    #+#             */
/*   Updated: 2022/05/15 14:34:44 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Finds the index where the number will be put
 * max - if the number is bigger than max it has to go after max
 * @param arr [int *] array to iterate through
 * @param nb [int] number 
 */
int	ps_iterate_a(int *arr, int nb)
{
	int	size;
	int	i;
	int	max;

	max = ps_find_max(arr);
	size = arr[0];
	i = 2;
	if (nb > arr[max])
		return (max);
	while (i <= size)
	{
		// ft_printf("nb = %d, arr[1] = %d, arr[size] = %d, arr[i] = %d\n", nb, arr[1], arr[size], arr[i]);
		if (nb < arr[1] && nb > arr[size])
		{
			i = 1;
			break ;
		}
		else if (nb < arr[i] && nb > arr[i - 1])
			break ;
		i++;
	}
	// printf("i = %d, size = %d\n", i, size);
	i--;
	if ((size / 2) < (i))
		i = (i - size);
	return (i);
}

/**
 * Calculates the position of the number on index in b
 * and returns the index with + to rotate up or - to 
 * reverse rotate
 * @param arr [int *] array to iterate through
 * @param idx [int] index of b
 */
int	ps_calc_b(int *arr, int idx)
{
	int	size;

	size = arr[0];
	idx--;
	if ((size / 2) < (idx))
		idx = (idx - size);
	return (idx);
}

/**
 * Compares the current solution with the new one
 * and calculates which one is the best
 * 0 - the number from the list
 * 1 - the amount of steps needed in stack a
 * 2 - the amount of steps needed in stack b
 * @param sol [int *] Array for solution
 * @param tmp [int *] Array for comparision
 */
int	ps_calc_best(int *sol, int *tmp)
{
	int	*sol_steps;
	int	*tmp_steps;
	int	i;
	int	ssteps;
	int	tsteps;

	i = 0;
	ssteps = 0;
	tsteps = 0;
	sol_steps = ps_calc_rotation(sol);
	tmp_steps = ps_calc_rotation(tmp);
	while (i < 3)
	{
		ssteps += ps_abs(sol_steps[i]);
		tsteps += ps_abs(tmp_steps[i]);
		i++;
	}
	free(sol_steps);
	free(tmp_steps);
	if (ssteps > tsteps)
		return (1);
	return (0);
}

/**
 * Find the cheapest move to push back to a
 * and returns an array with the solution
 * 0 - the number from the list
 * 1 - the amount of steps needed in stack a
 * 2 - the amount of steps needed in stack b
 * @param a [int *] Array copy of stack a
 * @param b [int *] Array copy of stack b
 */
int	*ps_find_cheapest_move(int *a, int *b)
{
	int	i;
	int	tmp[3];
	int	*solution;

	i = 1;
	solution = (int *)malloc(sizeof(int) * 3);
	solution[0] = INT_MAX;
	solution[1] = INT_MAX;
	solution[2] = INT_MAX;
	while (i <= b[0])
	{
		tmp[0] = b[i];
		tmp[1] = ps_iterate_a(a, b[i]);
		tmp[2] = ps_calc_b(b, i);
		// ft_printf("solution 0 = %d, a = %d, b = %d\n", tmp[0], tmp[1], tmp[2]);
		if (ps_calc_best(solution, tmp) || i == 1)
		{
			solution[0] = tmp[0];
			solution[1] = tmp[1];
			solution[2] = tmp[2];
		}
		i++;
	}
	return (solution);
}
