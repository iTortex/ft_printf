/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeforid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 15:12:25 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/13 19:43:16 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*writeforid(t_print *all, va_list *factor)
{
	all->str = ft_itoa(va_arg(*factor, int));
	if (all->afterdot != 0)
		all->checkad = all->afterdot;
	if (all->minus != '-')
	{
		if (!all->afterdot)
			all->afterdot = ft_strlen(all->str);
		if (all->afterdot < all->shir)
		{
			while (all->afterdot != all->shir)
			{
				all->shir--;
				write(1, " ", 1);
			}
		}
		if (all->afterdot > ft_strlen(all->str) && all->dot == '.')
		{
			while (all->afterdot != ft_strlen(all->str))
				{
					all->afterdot--;
					write(1, "0", 1);
				}
		}
		write(1, all->str, ft_strlen(all->str));
		all->i++;
	}
	if (all->minus == '-')
	{
		if (all->afterdot > ft_strlen(all->str) && all->dot == '.')
		{
			while (all->afterdot != ft_strlen(all->str))
				{
					all->afterdot--;
					write(1, "0", 1);
				}
		}
		write(1, all->str, ft_strlen(all->str));
		all->i++;
	}
	while (all->shir > all->checkad && all->shir != 0)
	{
		all->shir--;
		write(1, " ", 1);
	}
	free(all->str);
	return (0);
}