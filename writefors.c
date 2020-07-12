/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writefors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 14:06:01 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/12 18:27:56 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*writefors(t_print *all, va_list *factor)
{
	if (all->minus != '-')
	{
		all->str = va_arg(*factor, char *);
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
			}
		}
		write(1, all->str, all->afterdot);
		all->i++;
	}
	else
	{
		all->str = va_arg(*factor, char *);
		if (!all->afterdot)
			all->afterdot = ft_strlen(all->str);
		if (all->afterdot > ft_strlen(all->str))
			all->afterdot = ft_strlen(all->str);
		write(1, all->str, all->afterdot);
		all->i++;
		if (all->afterdot < all->shir)
		{
			while (all->afterdot != all->shir)
			{
				all->shir--;
				write(1, " ", 1);
			}
		}
	}
	return (0);
}