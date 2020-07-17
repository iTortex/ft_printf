/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:16:10 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/17 19:23:24 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void *prcnt(t_print *all, char *ptr)
{
	all->shir = ft_atoi(ptr);
	if (all->minus != '-')
	{
		while (all->shir - 1 != 0)
		{
			write(1, &all->zero, 1);
			all->shir--;
			all->exit++;
		}
		write(1, "%%", 1);
		all->exit++;
	}
	if (all->minus == '-' && all->zero != '0')
	{
		write(1, "%%", 1);
		all->exit++;
		while (all->shir - 1 != 0)
		{
			write(1, &all->zero, 1);
			all->shir--;
			all->exit++;
		}
	}
	if (all->minus == '-' && all->zero == '0')
	{
		write(1, "%%", 1);
		all->exit++;
		while (all->shir - 1 != 0)
		{
			write(1, " ", 1);
			all->shir--;
			all->exit++;
		}
	}
	return (0);
}

static void	*checkproc(const char *format, t_print *all)
{
	char *ptr;
	
	ptr = (&((char *)format)[all->i]);
	all->first = all->i;
	if (format[all->i] == '0')
		all->zero = '0';
	while (format[all->i] >= '0' && format[all->i] <='9')
		all->i++;
	if (format[all->i] == '%')
		prcnt(all, ptr);
	all->i = all->first;
	return (0);
}

void	*width(const char *format, t_print *all, va_list *factor)
{
	char *ptr;
	
	ptr = (&((char *)format)[all->i]);
	all->shir = ft_atoi(ptr);
	checkproc(format,all);
	while(format[all->i] >= '0' && format[all->i] <= '9')
		all->i++;
	if (format[all->i] == '*')
	{
		all->star = '*';
		all->i++;
		all->shir = va_arg(*factor, size_t);
	}
	if (all->shir < 0)
		all->shir *= -1;
	return (0);
}