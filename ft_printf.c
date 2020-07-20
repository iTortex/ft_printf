/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 18:09:19 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/20 15:32:52 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*checkforflags(const char *format, t_print *all, va_list *factor)
{
	while (format[all->i] == '0')
	{
		all->zero = '0';
		all->i++;
		if (format[all->i] == '-')
			all->zero = ' ';
	}
	while (format[all->i] == '-')
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
	if (format[all->i] == '%')
		writeforprcnt(all, format);
	if (format[all->i] == 's' && all->prcnt != '%')
		writefors(all, factor);
	if ((format[all->i] == 'i' || format[all->i] == 'd') && all->prcnt != '%')
		writeforid(all, factor);
	if (format[all->i] == 'c' && all->prcnt != '%')
		writeforc(all, factor);
	if ((format[all->i] == 'x' || format[all->i] == 'X') && all->prcnt != '%')
		writeforxX(format, all, factor);
	if (format[all->i] == 'u' && all->prcnt != '%')
		writeforu(all, factor);
	if (format[all->i] == 'p' && all->prcnt != '%')
		writeforp(all, factor);
	return (0);
}

static void	*obnul(t_print *all)
{
	all->i = 0;
	all->first = 0;
	all->afterdot = 0;
	all->shir = 0;
	all->exit = 0;
	all->checkad = 0;
	all->zero = ' ';
	return (0);
}

int		ft_printf(const char *format, ...)
{
	t_print all;
	va_list factor;
	
	obnul(&all);
	va_start(factor, format);
	while (format[all.i] != '\0')
	{
		if (format[all.i] == '%')
		{
			all.afterdot = 0;
			all.dot = ' ';
			all.str = NULL;
			all.i += 1;
			iforif(format, &all, &factor);
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
// 	// ft_printf("%-1c|", 'F');
// 	// unsigned int c = 11;
// 	//printf("%p|\n",&c);
// 	//printf("%20.10u|\n", c);
// 	//ft_printf("%20.10u|\n", c);
// 	//ft_printf("%10p|\n", &c);
// 	//printf("\n%i", f);
// 	// ft_printf("%llf|\n",42.5);
// 	// ft_printf("%.s\n", "hello");
// 	// int mx_u = 235;
// 	// int a05 = 15;
// 	// printf("%u%x\n", mx_u, mx_u);
// 	ft_printf("%05%wwww");
// 	return (0);
// }