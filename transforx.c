/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:16:24 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/20 20:12:37 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			*zapoln(t_print *all, int ost)
{
	int			i;

	i = 0;
	all->str = ft_calloc(sizeof(char), ost + 1);
	if (all->wrks == 0)
		all->str[0] = '0';
	while (all->wrks > 0)
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

void			*rev(t_print *all)
{
	char		*dup;
	int			i;
	int			j;

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

void			*transforx(t_print *all, const char *format)
{
	int			ost;
	int			j;

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
