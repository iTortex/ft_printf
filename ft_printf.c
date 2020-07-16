/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 18:09:19 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/16 20:35:28 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*checkforflags(const char *format, t_print *all, va_list *factor)
{
	if (format[all->i] == '0')
	{
		all->zero = '0';
		all->i++;
	}
	if (format[all->i] == '%')
	{
		write(1, "%%", 1);
		all->i++;
		all->exit++;
	}
	if (format[all->i] == '-')
	{
		all->minus = '-';
		all->i++;
	}
	if ((format[all->i] >= '0' && format[all->i] <= '9') || format[all->i] == '*')
		width(format, all, factor);
	if (format[all->i] == '.')
		workwithdot(format, all, factor);
	return (0);
}

void	*iforif(const char *format, t_print *all, va_list *factor)
{
	checkforflags(format, all, factor);
	if (format[all->i] == 's')
		writefors(all, factor);
	if (format[all->i] == 'i' || format[all->i] == 'd')
		writeforid(all, factor);
	if (format[all->i] == 'c')
		writeforc(all, factor);
	if (format[all->i] == 'x' || format[all->i] == 'X')
		writeforxX(format, all, factor);
	if (format[all->i] == 'u')
		writeforu(all, factor);
	if (format[all->i] == 'p' && all->dot != '.')
		writeforp(all, factor);
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
	all.exit = 0;
	all.checkad = 0;
	all.zero = ' ';
	va_start(factor, format);
	while (format[all.i] != '\0')
	{
		if (format[all.i] == '%')
		{
			all.i += 1;
			iforif(format, &all, &factor);
			all.afterdot = 0;
			all.dot = ' ';
		}
		if (all.i < ft_strlen(format) && format[all.i] != '%')
		{
			write(1, &format[all.i], 1);
			all.exit++;
			all.i++;
		}
	}
	va_end(factor);
	return (all.exit);
}

// int main (void)
// {	
// 	// char *str = "Hello World!";
// 	// printf("%0.5d|\n", 111);
// 	// ft_printf("%0.5d|", 111);
// 	// printf("%-1c|", 'F');
// 	// ft_printf("%-1c|", 'F');
// 	//unsigned int c = 11;
// 	//printf("%p|\n",&c);
// 	//printf("%20.10u|\n", c);
// 	//ft_printf("%20.10u|\n", c);
// 	//ft_printf("%10p|\n", &c);
// 	//printf("\n%i", f);
// 	// ft_printf("%llf|\n",42.5);
// //	ft_printf("%.s\n", "hello");
// 	ft_printf("%.s", "hello");
// 	return (0);
// }