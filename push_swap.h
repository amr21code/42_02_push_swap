/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:05:12 by anruland          #+#    #+#             */
/*   Updated: 2022/05/15 18:11:43 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# define INT_MAX   2147483647 
# define INT_MIN   -2147483648

typedef struct s_liseq
{
	int	*list;
	int	*length;
	int	*sequence;
	int	len;
}	t_liseq;

/* ps_s.c */
void	ps_swap(t_list **head, char list, int ss);
void	ps_ss(t_list **a, t_list **b);

/* ps_p.c */
void	ps_push(t_list **src, t_list **dest, char srclst);

/* ps_r.c */
void	ps_rotate(t_list **head, char list, int rr);
void	ps_rr(t_list **a, t_list **b);

/* ps_rr.c */
void	ps_rotate_reverse(t_list **head, char list, int rrr);
void	ps_rrr(t_list **a, t_list **b);

/* ps_init.c*/
int		ps_init_list(t_list **a, int ac, char **av);
void	ps_init_arrays(t_liseq *lis, t_list *a);
void	ps_init_arr_bestelem(int **acpy, int **bcpy, t_list *a, t_list *b);
void	ps_update_idx(t_list *a);

/* ps_tests.c */
int		ps_check_sort(t_list *head, char sort);
void	ps_print_list(t_list *a, t_list *b);

/* ps_precheck.c */
int		ft_isdigit_str(char *str);
int		ps_error_check(int ac, char **av);

/* ps_lis.c */
int		*ps_get_sequence(t_liseq lis, int i);
int		*ps_find_lis(t_list *a);
int		ps_find_lowest(t_list *lst);
int		ps_check_non_lis(int *arr, int nb);
t_list	*ps_rm_non_lis(int *arr, t_list *a, t_list **b);

/* ps_cheapest.c */
int		ps_iterate_a(int *arr, int nb);
int		ps_calc_b(int *arr, int idx);
int		ps_calc_best(int *sol, int *tmp);
int		*ps_find_cheapest_move(int *a, int *b);

/* ps_helper1.c */
t_list	*ps_duplicate_lst(t_list *lst);
int		ps_find_max(int *arr);
int		ps_abs(int nb);
void	ps_rotate_arr_list(t_liseq *lis);
int		*ps_calc_rotation(int *solution);
int		ps_find_lowest_idx(t_liseq lis);

/* ps_helper2.c */
void	ps_del(void *lst);
void	ft_lstclear_ptr(t_list **lst);
int		ps_smallest(int *arr);
int		ps_rest_a(int *arr, int *rotation);
int		ps_rest_b(int *arr, int *rotation);

/* ps_smallstacks.c */
void	ps_sort_small(t_list **a, t_list **b);
void	ps_sort_lt3(t_list **a, t_list **b);
void	ps_sort_lt5(t_list **a, t_list **b);

/* ps_helper3.c */
void	ps_destroy_big(t_list **a, t_list **b, int *arr);
void	ps_destroy_small(t_list **a, t_list **b);
void	ps_exec_smart_rotations(t_list **a, t_list **b, int *rotation, int j);
void	ps_freelis(t_liseq *lis);

#endif
