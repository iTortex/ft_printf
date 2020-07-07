/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 18:09:19 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/07 19:54:57 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	*checkforflags(const char *format, t_print *all, va_list *factor)
{
	if (format[all->i] == '.')
	{
		char *pnt;
		pnt = NULL;
		all->dot = '.';
		all->i++;
		all->first = all->i;
		while (format[all->i] >= '0' && format[all->i] <= '9')
			all->i++;
		if (all->i - all->first > 0)
		{
			//*pnt = format[all.first];
			printf("%i\n", ft_atoi(format));
			all->afterdot = ft_atoi(format);
			printf("|%i|\n", all->afterdot);
		}
		if (all->i == '*')
		{
			all->star = '*';
			all->i++;
			all->afterdot = va_arg(*factor,int);
		}
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	t_print all;
	va_list factor;
	
	all.i = 0;
	all.first = 0;
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
			{
				checkforflags(format, &all, &factor);
			}
			if (format[all.i] == 's')
			{
				all.str = va_arg(factor, char *);
				if (!all.afterdot)
					all.afterdot = ft_strlen(all.str);
				write(1, all.str, all.afterdot);
			}
		}
		all.i++;
		write(1, &format[all.i], 1);
	}
	va_end(factor);
	return (0);
}

int main (void)
{	
	char *str = "nu chto tam?";
	printf("|%.5saaaaa|\n", str);
	ft_printf("%.5saaaa", str);
	return (0);
}