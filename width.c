/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 16:12:16 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/14 16:06:40 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*width(const char *format, t_print *all, va_list *factor)
{
	char *ptr;
	ptr = (&((char *)format)[all->i]);
	all->shir = ft_atoi(ptr);
	while(format[all->i] >= '0' && format[all->i] <= '9')
		all->i++;
	if (format[all->i] == '*')
	{
		all->star = '*';
		all->i++;
		all->shir = va_arg(*factor, size_t);
	}
	return (0);
}