/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeforxX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:48:09 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/17 16:48:27 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void *minusnothere(t_print *all)
{
	if (!all->afterdot)
		all->afterdot = ft_strlen(all->str);
	if (all->afterdot < all->shir)
	{
		while (all->afterdot != all->shir)
		{
			all->shir--;
			write(1, " ", 1);
		}
	}
	if (all->afterdot > ft_strlen(all->str) && all->dot == '.')
	{
		while (all->afterdot != ft_strlen(all->str))
			{
				all->afterdot--;
				write(1, "0", 1);
			}
	}
	write(1, all->str, ft_strlen(all->str));
	all->i++;
	return (0);
}

void	*zapoln(t_print *all, int ost)
{
	int i;

	i = 0;
	all->str = ft_calloc(sizeof(char), ost + 1);
	while (all->wrks != 0)
	{
		if (all->wrks % 16 > 9 && all->wrks % 16 < 16)
		{
			all->str[i] = all->wrks % 16 + all->six;
			i++;
		}
		if (all->wrks % 16 < 10 && all->wrks % 16 >= 0)
		{
			all->str[i] = all->wrks % 16 + 48;
			i++;
		}
		all->wrks /= 16;
	}
	return (0);
}

void	*rev(t_print *all)
{
	char *dup;
	int i;
	int j;
	
	i = 0;
	j = ft_strlen(all->str);
	dup = ft_calloc(sizeof(char), j + 1);
	while (all->str[i])
	{
		dup[i] = all->str[i];
		i++;
	}
	i = 0;
	j--;
	while (j >= 0)
	{
		all->str[i] = dup[j];
		i++;
		j--;
	}
	free(dup);
	return (0);
}

void	*transfor(t_print *all, const char *format)
{
	int ost;
	int j;
	
	j = all->wrks;
	ost = 0;
	if (format[all->i] == 'X')
		all->six = 55;
	else
		all->six = 87;
	while (all->wrks != 0)
	{
		all->wrks /= 16;
		ost++;
	}
	all->wrks = j;
	zapoln(all, ost);
	rev(all);
	return (0);
}

void	*writeforxX(const char *format, t_print *all, va_list *factor)
{
	all->wrks = va_arg(*factor, unsigned int);
	transfor(all, format);
	if (all->afterdot != 0)
		all->checkad = all->afterdot;
	if (all->minus != '-')
		minusnothere(all);
	if (all->minus == '-')
	{
		if (all->afterdot > ft_strlen(all->str) && all->dot == '.')
		{
			while (all->afterdot != ft_strlen(all->str))
				{
					all->afterdot--;
					write(1, "0", 1);
					all->exit++;
				}
		}
		write(1, all->str, ft_strlen(all->str));
		all->i++;
		all->exit +=  ft_strlen(all->str);
	}
	while (all->shir - ft_strlen(all->str) != all->checkad && all->shir != 0)
	{
		all->shir--;
		write(1, " ", 1);
		all->exit++;
	}
	free(all->str);
	return (0);
}