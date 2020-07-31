/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeforprcnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:06:23 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/24 15:47:08 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	minusnothere(t_print *all, const char *format)
{
	if (all->shir != 0)
		all->shir--;
	while (all->shir--)
	{
		write(1, &all->zero, 1);
		all->exit += 1;
		if (all->shir == 0)
		{
			write(1, "%%", 1);
			all->exit++;
		}
	}
	while (format[all->i] != '%' && format[all->i])
	{
		write(1, &format[all->i], 1);
		all->exit++;
		all->i++;
	}
}

static void	*minushere(t_print *all, const char *format)
{
	if (format[all->i] == '%')
	{
		write(1, "%%", 1);
		all->exit++;
		all->i++;
		if (all->shir != 0)
			all->shir--;
	}
	while (all->shir != 0)
	{
		all->shir--;
		write(1, " ", 1);
		all->exit++;
	}
	while (format[all->i] != '%' && all->shir != 0)
	{
		write(1, &format[all->i], 1);
		all->exit++;
		all->i++;
	}
	return (0);
}

void		*writeforprcnt(t_print *all, const char *format)
{
	if (format[all->i] == '%' && all->shir == 0)
	{
		write(1, "%%", 1);
		all->exit++;
		all->i++;
	}
	if (all->minus != '-')
		minusnothere(all, format);
	if (all->minus == '-')
		minushere(all, format);
	return (0);
}
