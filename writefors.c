/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writefors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 14:06:01 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/14 18:48:48 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*minushere(t_print *all)
{
	if (!all->afterdot)
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

void	*writefors(t_print *all, va_list *factor)
{
	all->str = va_arg(*factor, char *);
	if (all->minus != '-')
	{
		if (!all->afterdot)
			all->afterdot = ft_strlen(all->str);
		if (all->afterdot > ft_strlen(all->str))
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
		write(1, all->str, all->afterdot);
		all->exit += all->afterdot;
		all->i++;
	}
	if (all->minus == '-')
		minushere(all);
	return (0);
}