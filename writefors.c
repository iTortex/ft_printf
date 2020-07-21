/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writefors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 14:06:01 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/21 18:51:04 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		*minushere(t_print *all)
{
	if (!all->afterdot || all->afterdot < 0)
		all->afterdot = ft_strlen(all->str);
	if (all->afterdot > ft_strlen(all->str))
		all->afterdot = ft_strlen(all->str);
	write(1, all->str, all->afterdot);
	all->exit += all->afterdot;
	all->i++;
	if (all->afterdot < all->shir)
	{
		while (all->afterdot != all->shir)
		{
			all->shir--;
			write(1, " ", 1);
			all->exit++;
		}
	}
	return (0);
}

static void		*minusnothere(t_print *all)
{
	if (!all->afterdot || all->afterdot < 0)
		all->afterdot = ft_strlen(all->str);
	if (all->afterdot > ft_strlen(all->str))
		all->afterdot = ft_strlen(all->str);
	if (all->afterdot < all->shir)
	{
		while (all->afterdot != all->shir)
		{
			all->shir--;
			write(1, &all->zero, 1);
			all->exit++;
		}
	}
	write(1, all->str, all->afterdot);
	all->exit += all->afterdot;
	all->i++;
	return (0);
}

static void		*ifnull(t_print *all)
{
	if ((all->str = ft_calloc(sizeof(char), 8)) == NULL)
		all->error = -1;
	all->str = "(null)";
	if (all->minus != '-')
		minusnothere(all);
	if (all->minus == '-')
		minushere(all);
	all->str = NULL;
	free(all->str);
	return (0);
}

static void		*somecase(t_print *all)
{
	while (all->shir--)
	{
		all->zero = ' ';
		write(1, &all->zero, 1);
		all->exit += 1;
	}
	all->i++;
	return (0);
}

void			*writefors(t_print *all, va_list *factor)
{
	all->str = va_arg(*factor, char *);
	if (all->dot == '.' && all->afterdot == 0 && all->shir != 0)
	{
		somecase(all);
		return (0);
	}
	if (all->dot == '.' && all->afterdot == 0 && all->shir == 0)
	{
		all->i++;
		return (0);
	}
	if (all->str == NULL)
	{
		ifnull(all);
		return (0);
	}
	if (all->minus != '-')
		minusnothere(all);
	if (all->minus == '-')
		minushere(all);
	all->afterdot = 0;
	return (0);
}
