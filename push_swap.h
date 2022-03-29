/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:05:12 by anruland          #+#    #+#             */
/*   Updated: 2022/03/28 16:48:37 by anruland         ###   ########.fr       */
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

long	ft_atol(const char *str);
void	ps_swap(t_list **head, char list);
void	ps_ss(t_list **a, t_list **b);
void	ps_push(t_list **src, t_list **dest, char srclst);
void	ps_rotate(t_list **head, char list);
void	ps_rr(t_list **a, t_list **b);
void	ps_rotate_reverse(t_list **head, char list);
void	ps_rrr(t_list **a, t_list **b);

#endif
