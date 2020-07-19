/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeforp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:17:49 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/19 19:17:58 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	*zapoln(t_print *all, int ost)
{
	int i;

	i = 0;
	all->str = ft_calloc(sizeof(char), ost + 1);
	if (all->point == 0)
		all->str[0] = '0';
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
	if (all->shir < all->afterdot && all->dot == '.')
	{
		write(1, "0x", 2);
		all->checkforminus = 1;
	}
	if (!all->afterdot || all->afterdot < ft_strlen(all->str))
		all->afterdot = ft_strlen(all->str);
	all->shir -= 2;
	if (all->afterdot < all->shir)
	{
		if (all->first == 0 && all->dot == '.')
			all->shir++;
		while (all->shir - all->afterdot > 0)
		{
			if (all->shir >= all->afterdot && all->dot == '.')
			{
				write(1, " ", 1);
				all->exit++;
			}
			else if (all->shir >= all->afterdot && all->dot != '.')
			{
				write(1, &all->zero, 1);
				all->exit++;
			}
			all->shir--;
		}
	}
	if (all->afterdot > ft_strlen(all->str) && all->dot == '.')
	{
		while (all->afterdot != ft_strlen(all->str))
			{
				all->shir--;
				all->afterdot--;
				write(1, "0", 1);
				all->exit++;
			}
	}
	if (all->checkforminus != 1)
		write(1, "0x", 2);
	all->exit += 2;
	if (all->first > 0 || all->dot != '.')
	{
		write(1, all->str, ft_strlen(all->str));
		all->exit = all->exit + ft_strlen(all->str);
	}
	all->i++;
	return (0);
}

void	*writeforp(t_print *all, va_list *factor)
{
	all->first = all->afterdot;
	all->point = va_arg(*factor, long long);
	if (all->point == 0)
		all->str = "0";
	transfor(all);
	if (all->afterdot != 0)
		all->checkad = all->afterdot;
	if (all->minus != '-')
		minusnotherep(all);
	if (all->minus == '-')
	{
		if (all->checkforminus == 1)
		{
			write(1, "-", 1);
			all->exit++;
		}
		if (all->afterdot > ft_strlen(all->str) && all->dot == '.')
		{
			while (all->afterdot != ft_strlen(all->str))
				{
					all->shir--;
					all->afterdot--;
					write(1, "0", 1);
					all->exit++;
				}
		}
		write(1, "0x", 2);
		all->shir -= 2;
		all->exit += 2;
		write(1, all->str, ft_strlen(all->str));
		all->i++;
		all->exit += ft_strlen(all->str);
	}
	if (all->shir <= ft_strlen(all->str))
		all->shir = 0;
	while (all->shir - ft_strlen(all->str) > 0 &&
	all->shir - ft_strlen(all->str) && all->shir > 0)
	{
		all->shir--;
		write(1, &all->zero, 1);
		all->exit++;
	}
	free(all->str);
	return (0);
}