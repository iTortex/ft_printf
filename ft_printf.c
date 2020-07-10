/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 18:09:19 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/10 20:20:55 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	*checkforflags(const char *format, t_print *all, va_list *factor)
{
	if (format[all->i] >= '1' && format[all->i] <= '9')
		width(format, all);
	if (format[all->i] == '.')
		workwithdot(format, all, factor);
	// if (all->afterdot < all->shir)
	// {
	// 	while (all->afterdot != all->shir)
	// 	{
	// 		printf("%u", all->shir);
	// 		printf("%zu", all->afterdot);
	// 		all->shir--;
	// 		write(1, " ", 1);
	// 	}
	//}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	t_print all;
	va_list factor;
	
	all.i = 0;
	all.first = 0;
	all.shir = 0;
	va_start(factor, format);
	while (format[all.i])
	{
		if (format[all.i] == '%')
		{
			all.i += 1;
			if (format[all.i] != 'i' || format[all.i] != 'd' || 
			format[all.i] != 's' || format[all.i] != 'c' 
			|| format[all.i] != 'p' || format[all.i] != 'X' 
			|| format[all.i] != 'x'
			|| format[all.i] != 'p' || format[all.i] != 'u')
				checkforflags(format, &all, &factor);
			if (format[all.i] == 's')
			{
				all.str = va_arg(factor, char *);
				if (!all.afterdot)
					all.afterdot = ft_strlen(all.str);
				if (all.afterdot > ft_strlen(all.str))
					all.afterdot = ft_strlen(all.str);
				if (all.afterdot < all.shir)
				{
					while (all.afterdot != all.shir)
					{
					all.shir--;
					write(1, " ", 1);
					}
				}
				write(1, all.str, all.afterdot);
				all.i++;
			}
		}
		write(1, &format[all.i], 1);
		all.i++;
	}
	va_end(factor);
	return (0);
}

int main (void)
{	
	char *str = "Hello";
	//printf("%10i\n", 100);
	//ft_printf("%10i\n", 100);
	printf("str = %19.*s\n%.*s\nstr = %.36s\n", 4, str,  20, str, str);
	ft_printf("\n\nstr = %19.*s\n%.*s\nstr = %.36s\n", 4, str,  20, str, str);
	return (0);
}