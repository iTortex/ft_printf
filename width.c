/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:16:10 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/20 20:13:19 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		*width(const char *format, t_print *all, va_list *factor)
{
	char	*ptr;

	ptr = (&((char *)format)[all->i]);
	all->shir = ft_atoi(ptr);
	while (format[all->i] >= '0' && format[all->i] <= '9')
		all->i++;
	if (format[all->i] == '*')
	{
		all->star = '*';
		all->i++;
		all->shir = va_arg(*factor, size_t);
	}
	if (all->shir < 0)
	{
		all->minus = '-';
		all->shir *= -1;
	}
	return (0);
}
