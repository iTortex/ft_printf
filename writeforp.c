/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeforp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:51:57 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/14 17:31:15 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	*zapoln(t_print *all, int ost)
{
	int i;

	i = 0;
	all->str = ft_calloc(sizeof(char), ost + 1);
	while (all->point != 0)
	{
		if (all->point % 16 > 9 && all->point % 16 < 16)
		{
			all->str[i] = all->point % 16 + all->six;
			i++;
		}
		if (all->point % 16 < 10 && all->point % 16 >= 0)
		{
			all->str[i] = all->point % 16 + 48;
			i++;
		}
		all->point /= 16;
	}
	return (0);
}

static	void	*rev(t_print *all)
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

static	void	*transfor(t_print *all)
{
	int ost;
	long long int j;
	
	j = all->point;
	ost = 0;
	all->six = 87;
	while (all->point != 0)
	{
		all->point /= 16;
		ost++;
	}
	all->point = j;
	zapoln(all, ost);
	rev(all);
	return (0);
}

static void	*minusnotherep(t_print *all)
{
	if (!all->afterdot)
		all->afterdot = ft_strlen(all->str);
	if (all->afterdot < all->shir)
	{
		while (all->afterdot != all->shir - 2)
		{
			all->shir--;
			write(1, " ", 1);
			all->exit++;
		}
	}
	write(1, "0x", 2);
	write(1, all->str, ft_strlen(all->str));
	all->exit = all->exit + 2 + ft_strlen(all->str);
	all->i++;
	return (0);
}

void	*writeforp(t_print *all, va_list *factor)
{
	all->point = va_arg(*factor, long long);
	transfor(all);
	if (all->afterdot != 0)
		all->checkad = all->afterdot;
	if (all->minus != '-')
		minusnotherep(all);
	if (all->minus == '-')
	{
		write(1, "0x", 2);
		write(1, all->str, ft_strlen(all->str));
		all->exit = all->exit + 2 + ft_strlen(all->str);
		all->i++;
	}
	while (all->shir - 2 > all->checkad && all->shir != 0)
	{
		all->shir--;
		write(1, " ", 1);
		all->exit++;
	}
	free(all->str);
	return (0);
}