/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeforu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:58:51 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/14 18:33:46 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*minusnothereu(t_print *all)
{
	if (!all->afterdot)
		all->afterdot = ft_strlen(all->str);
	if (all->afterdot < all->shir)
	{
		while (all->afterdot != all->shir)
		{
			all->shir--;
			write(1, " ", 1);
			all->exit++;
		}
	}
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
	all->exit += ft_strlen(all->str);
	all->i++;
	return (0);
}

static void	*minushere(t_print *all)
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
	all->exit += ft_strlen(all->str);
	all->i++;
	return (0);
}

static	void	*whiles(t_print *all)
{
	while (all->shir - ft_strlen(all->str) > all->checkad && all->shir != 0)
	{
		all->shir--;
		write(1, " ", 1);
		all->exit++;
	}
	while(all->shir > all->checkad && all->shir == 0)
	{
		all->shir--;
		write(1, " ", 1);
		all->exit++;
	}
	return (0);
}

void	*writeforu(t_print *all, va_list *factor)
{
	all->wrks = va_arg(*factor, unsigned int);
	all->str = ft_utoa(all->wrks);
	if (all->afterdot != 0)
		all->checkad = all->afterdot;
	if (all->minus != '-')
		minusnothereu(all);
	if (all->minus == '-')
		minushere(all);
	whiles(all);
	free(all->str);
	return (0);
}