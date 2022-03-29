/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:04:29 by anruland          #+#    #+#             */
/*   Updated: 2022/03/29 11:28:59 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit_str(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == '-' || str[j] == '+')
			j++;
		if (!ft_isdigit(str[j]))
			return (1);
		j++;
	}
	return (0);
}

int	ps_error_check(int ac, char **av)
{
	int		i;
	int		j;
	long	atol;

	i = 1;
	while (i < ac)
	{
		j = i - 1;
		atol = ft_atol(av[i]);
		while (j >= 0)
		{
			if (atol > INT_MAX || atol < INT_MIN
				|| ft_isdigit_str(av[i]) || ft_atol(av[j]) == atol)
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			}
			j--;
		}
		i++;
	}
	return (0);
}

int	ps_check_sort(t_list *head, char sort)
{
	t_list	*temp;

	while (head && head->next)
	{
		temp = head->next;
		if (sort == 'a')
		{
			if (*((int *)head->content) > *((int *)temp->content))
				return (0);
		}
		else if (sort == 'd')
		{
			if (*((int *)head->content) < *((int *)temp->content))
				return (0);
		}
		head = head->next;
	}
	return (1);
}

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
		ft_lstadd_back(a, new);
		i++;
	}
	if (ps_check_sort(*a, 'a'))
		return (0);
	return (1);
}

void	ps_print_list(t_list *a, t_list *b)
{
	while (a || b)
	{
		if (a)
		{
			ft_printf("%d\t\t\t", *((int *)a->content));
			a = a->next;
		}
		else
			ft_printf(" \t\t\t");
		if (b)
		{
			ft_printf("%d\n", *((int *)b->content));
			b = b->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("----\t\t\t----\n");
	ft_printf("a\t\t\tb\n\n");
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac < 2 || ps_error_check(ac, av) || !ps_init_list(&a, ac, av))
		return (0);
	while (!ps_check_sort(a, 'a') || ft_lstsize(b) > 0)
	{
		if (ft_lstsize(a) > 1
			&& *((int *)a->content) > *((int *)(a->next)->content))
			ps_swap(&a, 'a');
		else
			ps_push(&a, &b, 'a');
		if (ft_lstsize(a) == 0 && ps_check_sort(b, 'd'))
		{
			while (b)
				ps_push(&b, &a, 'b');
		}
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
	}
	return (0);
}
