/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeforid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 15:12:25 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/17 18:47:53 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void *minusnothere(t_print *all)
{
	if ((all->checkforminus == 1 && all->dot == '.') ||
	(all->checkforminus == 1 && all->zero == '0'))
	{
		write(1, "-", 1);
		all->exit++;
	}
	if (!all->afterdot || all->afterdot < ft_strlen(all->str))
		all->afterdot = ft_strlen(all->str);
	if (all->afterdot < all->shir)
	{
	while (all->shir - all->afterdot > 0)
	{
		all->shir--;
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
	if (all->checkforminus == 1 && all->dot != '.' && all->zero != '0')
	{
		write(1, "-", 1);
		all->exit++;
	}
	write(1, all->str, ft_strlen(all->str));
	all->exit += ft_strlen(all->str);
	all->i++;
	return (0);
}

void	*writeforid(t_print *all, va_list *factor)
{
	all->id = va_arg(*factor, int);
	if (all->id < 0)
	{
		all->checkforminus = 1;
		if (all->shir != 0)
			all->shir--;
		all->str = (ft_itoa(-1 * all->id));
	}
	else
		all->str = ft_itoa(all->id);
	if (all->dot == '.' && all->id == 0 && (all->afterdot <= 0 || !all->afterdot))
	{
		while (all->shir--)
		{
			write(1, " ", 1);
			all->exit++;
		}
		all->i++;
		return (0);
	}
	if (all->afterdot != 0)
		all->checkad = all->afterdot;
	if (all->minus != '-')
		minusnothere(all);
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