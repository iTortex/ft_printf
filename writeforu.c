/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeforu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:58:51 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/21 18:52:31 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		shmaf(t_print *all)
{
	while (all->shir - all->afterdot > 0)
	{
		if (all->shir >= all->afterdot && all->dot == '.')
		{
			write(1, " ", 1);
			all->exit++;
			all->shir--;
		}
		else if (all->shir >= all->afterdot && all->dot != '.')
		{
			write(1, &all->zero, 1);
			all->exit++;
			all->shir--;
		}
	}
}

static void		*minusnothere(t_print *all)
{
	if (!all->afterdot || all->afterdot < ft_strlen(all->str))
		all->afterdot = ft_strlen(all->str);
	if (all->afterdot < all->shir)
		shmaf(all);
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
	all->exit += ft_strlen(all->str);
	all->i++;
	return (0);
}

static void		*minushere(t_print *all)
{
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
	if (all->shir <= ft_strlen(all->str))
		all->shir = 0;
	while (all->shir - ft_strlen(all->str) > 0 &&
	all->shir - ft_strlen(all->str) && all->shir > 0)
	{
		all->shir--;
		write(1, &all->zero, 1);
		all->exit++;
	}
	return (0);
}

static	void	*whiles(t_print *all)
{
	while (all->shir - ft_strlen(all->str) > all->checkad && all->shir != 0)
	{
		all->shir--;
		write(1, &all->zero, 1);
		all->exit++;
	}
	while (all->shir > all->checkad && all->shir == 0)
	{
		all->shir--;
		write(1, &all->zero, 1);
		all->exit++;
	}
	return (0);
}

void			*writeforu(t_print *all, va_list *factor)
{
	all->wrks = va_arg(*factor, unsigned int);
	if ((all->str = ft_utoa(all->wrks)) == NULL)
		all->error = -1;
	if (all->dot == '.' && (all->afterdot <= 0 || !all->afterdot))
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
		minushere(all);
	whiles(all);
	all->str = NULL;
	free(all->str);
	return (0);
}
