/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workwithid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 17:18:04 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/05 18:59:38 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*workwithid(const char *format, t_print check)
{
	if (check.first == check.i)
	{
		check.num = va_arg(check.look, int);
		ft_putnbr_fd(check.num, 1);
	}
	return (0);
}