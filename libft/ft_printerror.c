/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:32:46 by anruland          #+#    #+#             */
/*   Updated: 2022/05/13 16:44:52 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printerror(char *errormsg)
{
	ft_putstr_fd(errormsg, 2);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}
