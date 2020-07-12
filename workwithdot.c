/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workwithdot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 18:02:43 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/12 18:35:19 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*workwithdot(const char *format, t_print *all, va_list *factor)
{
	char *pnt;
	pnt = (&((char *)format)[all->i]);
	all->dot = '.';
	all->i++;
	all->first = all->i;
	while (format[all->i] >= '0' && format[all->i] <= '9')
		all->i++;
	if (all->i - all->first > 0)
		all->afterdot = ft_atoi(++pnt);
	if (format[all->i] == '*')
	{
		all->star = '*';
		all->i++;
		all->afterdot = va_arg(*factor,size_t);
	}
	return (0);
}