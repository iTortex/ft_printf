/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 18:09:19 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/12 19:54:16 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*checkforflags(const char *format, t_print *all, va_list *factor)
{
	while (format[all->i] == '-')
	{
		all->minus = '-';
		all->i++;
	}
	while (format[all->i] == '0')
		{
			all->zero = '0';
			all->i++;
		}
	if ((format[all->i] >= '1' && format[all->i] <= '9') || format[all->i] == '*')
		width(format, all, factor);
	if (format[all->i] == '.')
		workwithdot(format, all, factor);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	t_print all;
	va_list factor;
	
	all.i = 0;
	all.first = 0;
	all.shir = 0;
	all.afterdot = 0;
	va_start(factor, format);
	while (format[all.i])
	{
		if (format[all.i] == '%')
		{
			all.i += 1;
			// if (format[all.i] != 'i' || format[all.i] != 'd' ||
			// format[all.i] != 's' || format[all.i] != 'c' 
			// || format[all.i] != 'p' || format[all.i] != 'X' 
			// || format[all.i] != 'x'
			// || format[all.i] != 'p' || format[all.i] != 'u')
			checkforflags(format, &all, &factor);
			if (format[all.i] == 's')
				writefors(&all, &factor);
			if (format[all.i] == 'i' || format[all.i] == 'd')
				writeforid(&all, &factor);
			if (format[all.i] == 'c')
				writeforc(&all, &factor);
		}
		if (format[all.i] != '%')
		{
			write(1, &format[all.i], 1);
				all.i++;
		}
	}
	va_end(factor);
	return (0);
}

int main (void)
{	
	//char *str = "   Hello World!";
	//printf("chislo ravno: %.*s%5.4d|\n", 4, "Hello world", 111);
	//ft_printf("chislo ravno: %.*s%5.4d|\n", 4, "Hello world", 111);
	printf("%-1c|", 'F');
	ft_printf("%-1c|", 'F');
	//printf("%s\n", str);
	//ft_printf("%s", str);
	return (0);
}