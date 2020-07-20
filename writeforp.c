/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeforp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:17:49 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/20 20:27:54 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		*atfirst(t_print *all)
{
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
	return (0);
}

static void		*minushere(t_print *all)
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
	return (0);
}

static void		minusnotherep(t_print *all)
{
	if (all->shir < all->afterdot && all->dot == '.')
	{
		write(1, "0x", 2);
		all->checkforminus = 1;
	}
	atfirst(all);
	if (all->afterdot > ft_strlen(all->str) && all->dot == '.')
	{
		while (all->afterdot-- != ft_strlen(all->str))
		{
			all->shir--;
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
}

void			*writeforp(t_print *all, va_list *factor)
{
	all->first = all->afterdot;
	all->point = va_arg(*factor, long long);
	if (all->point == 0)
		all->str = "0";
	transforp(all);
	if (all->afterdot != 0)
		all->checkad = all->afterdot;
	if (all->minus != '-')
		minusnotherep(all);
	if (all->minus == '-')
		minushere(all);
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
