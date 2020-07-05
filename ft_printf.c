/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 18:09:19 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/05 19:10:23 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	*workwithid(const char *format, t_print check)
{
	if (check.first == check.i && format[check.i] == 'i')
	{
		check.num = va_arg(check.look, int);
		ft_putnbr_fd(check.num, 1);
	}
	return (0);
}

void *afterprcnt(const char *format, t_print check)
{
	check.i++;
	check.first = check.i;
	while (format[check.i] != 'i' || format[check.i] != 'd' || 
	format[check.i] != 's' || format[check.i] != 'c' || format[check.i] != 'p' ||
	format[check.i] != 'X' || format[check.i] != 'x'
	|| format[check.i] != 'p' || format[check.i] != 'u')
	{
		check.i++;
	}
	if (format[check.i] == 'i' || format[check.i] == 'd')
		workwithid(format, check);
	return (0);
}
int ft_printf(const char *format, ...)
{
	t_print check;
	
	check.i = 0;
	check.first = 0;
	va_start(check.look, format);
	while (format[check.i])
	{
		if (format[check.i] == '%')
		{
			afterprcnt(format, check);
			// i++;
			// if (format[i] == 'i' || format[i] == 'd')
			// 	check.num = va_arg(look, int);
			// if (format[i] == 's')
			// 	check.str = va_arg(look, char*);
		}
		check.i++;
	}
	return 0;
}



int main (void)
{
	int gg = 123000000;
	
	//char *str = "nu chto tam?";
	ft_printf("%i", gg);
	return (0);
}