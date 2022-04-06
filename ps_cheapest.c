/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cheapest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:25:59 by anruland          #+#    #+#             */
/*   Updated: 2022/04/06 19:26:07 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ps_iterate_a(int *arr, int nb)
{
	int	size;
	int	i;
	int	max;

	max = ps_find_max(arr);
	size = arr[0];
	i = 1;
	if (nb > arr[max])
		return (max);
	while (i <= size)
	{
		if (nb < arr[i])
			break ;
		i++;
	}
	i--;
	if ((size / 2) < (i))
	{
		i = (i - size);
	}

	return (i);
}

int	ps_calc_b(int *arr, int idx)
{
	int	size;

	size = arr[0];
	idx--;
	if ((size / 2) < (idx))
		idx = (idx - size);
	return (idx);
}

int	ps_calc_best(int *sol, int *tmp)
{
	if ((ps_abs(sol[1]) + ps_abs(sol[2])) > (ps_abs(tmp[1]) + ps_abs(tmp[2])))
		return (1);
	return (0);
}

int	*ps_find_cheapest_move(int *a, int *b)
{
	int	i;
	int	tmp[3];
	int	*solution;

	i = 1;
	solution = (int *)malloc(sizeof(int) * 3);
	while (i <= b[0])
	{
		tmp[0] = b[i];
		tmp[1] = ps_iterate_a(a, b[i]);
		tmp[2] = ps_calc_b(b, i);
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
