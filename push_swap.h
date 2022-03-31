/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:05:12 by anruland          #+#    #+#             */
/*   Updated: 2022/03/31 18:02:30 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libftprintf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# define INT_MAX   2147483647 
# define INT_MIN   -2147483648

/* ft_atol.c */
long	ft_atol(const char *str);

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

#endif
