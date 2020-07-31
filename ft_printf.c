/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 18:09:19 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/24 16:07:55 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			*checkforfla(const char *format, t_print *all, va_list *factor)
{
	while (format[all->i] == '0' || format[all->i] == '-')
	{
		if (format[all->i] == '-')
			all->minus = '-';
		if (format[all->i] == '0')
		{
			all->zero = '0';
			if (format[all->i] == '-')
				all->zero = ' ';
		}
		all->i++;
	}
	if ((format[all->i] >= '0' && format[all->i] <= '9')
	|| format[all->i] == '*')
		width(format, all, factor);
	if (format[all->i] == '.')
		workwithdot(format, all, factor);
	return (0);
}

void			*iforif(const char *format, t_print *all, va_list *factor)
{
	checkforfla(format, all, factor);
	if (format[all->i] == '%')
		writeforprcnt(all, format);
	if (format[all->i] == 's' && all->prcnt != '%')
		writefors(all, factor);
	if (all->afterdot < 0)
		all->afterdot = 1;
	if ((format[all->i] == 'i' || format[all->i] == 'd') && all->prcnt != '%')
		writeforid(all, factor);
	if (format[all->i] == 'c' && all->prcnt != '%')
		writeforc(all, factor);
	if ((format[all->i] == 'x' || format[all->i] == 'X') && all->prcnt != '%')
		writeforxx(format, all, factor);
	if (format[all->i] == 'u' && all->prcnt != '%')
		writeforu(all, factor);
	if (format[all->i] == 'p' && all->prcnt != '%')
		writeforp(all, factor);
	return (0);
}

static void		*obnul(t_print *all)
{
	all->first = 0;
	all->afterdot = 0;
	all->shir = 0;
	all->checkad = 0;
	all->zero = ' ';
	all->minus = ' ';
	all->dot = ' ';
	all->six = 0;
	all->checkforminus = 0;
	return (0);
}

static void		manewhile(const char *format, t_print *all, va_list *factor)
{
	while (format[all->i] != '\0')
	{
		if (format[all->i] == '%')
		{
			obnul(all);
			all->i += 1;
			iforif(format, all, factor);
		}
		if (all->i < ft_strlen(format) && format[all->i] != '%')
		{
			write(1, &format[all->i], 1);
			all->exit++;
			all->i++;
		}
	}
}

int				ft_printf(const char *format, ...)
{
	t_print		all;
	va_list		factor;

	all.exit = 0;
	all.i = 0;
	if (format == NULL)
		return (-1);
	va_start(factor, format);
	manewhile(format, &all, &factor);
	va_end(factor);
	if (all.error == -1 && all.exit != 0)
		all.exit = all.error;
	return (all.exit);
}
