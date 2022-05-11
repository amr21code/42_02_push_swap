/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:05:12 by anruland          #+#    #+#             */
/*   Updated: 2022/05/07 06:51:22 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# define INT_MAX   2147483647 
# define INT_MIN   -2147483648

typedef struct	s_lis
{
	int	*list;
	int	*length;
	int	*sequence;
};	t_lis

/* ps_s.c */
void	ps_swap(t_list **head, char list);
void	ps_ss(t_list **a, t_list **b);

/* ps_p.c */
void	ps_push(t_list **src, t_list **dest, char srclst);

/* ps_r.c */
void	ps_rotate(t_list **head, char list);
void	ps_rr(t_list **a, t_list **b);

/* ps_rr.c */
void	ps_rotate_reverse(t_list **head, char list);
void	ps_rrr(t_list **a, t_list **b);

/* ps_init.c*/
int		ps_init_list(t_list **a, int ac, char **av);

/* ps_tests.c */
int		ps_check_sort(t_list *head, char sort);
void	ps_print_list(t_list *a, t_list *b);

/* ps_precheck.c */
int		ft_isdigit_str(char *str);
int		ps_error_check(int ac, char **av);

/* ps_lis.c */
int		*ps_get_sequence(int **list, int **sequence, int **length, int len);
int		*ps_find_lis(t_list *a, int len);
int		ps_find_lowest(t_list *lst);
int		ps_check_non_lis(int *arr, int nb);
t_list	*ps_rm_non_lis(int *arr, t_list *a, t_list **b);

/* ps_cheapest.c */
int		ps_iterate_a(int *arr, int nb);
int		ps_calc_b(int *arr, int idx);
int		ps_calc_best(int *sol, int *tmp);
int		*ps_find_cheapest_move(int *a, int *b);

/* ps_helper1.c */
void	ps_init_arrays(int **list, int **length, int **sequence, t_list *a);
t_list	*ps_duplicate_lst(t_list *lst);
void	ps_init_arr_bestelem(int **acpy, int **bcpy, t_list *a, t_list *b);
int		ps_find_max(int *arr);
int		ps_abs(int nb);

int		*ps_calc_rotation(int *solution);

/* ps_helper2.c */
void	ps_del(void *lst);
void	ft_lstclear_ptr(t_list **lst);
int		ps_smallest(int *arr);
int		ps_rest_a(int *arr);
int		ps_rest_b(int *arr);

#endif
