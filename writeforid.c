/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeforid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 15:12:25 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/16 21:03:09 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void *minusnothere(t_print *all)
{
	if (!all->afterdot)
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

void	*writeforid(t_print *all, va_list *factor)
{
	all->str = ft_itoa(va_arg(*factor, int));
	if (all->afterdot != 0)
		all->checkad = all->afterdot;
	if (all->minus != '-')
		minusnothere(all);
	if (all->minus == '-')
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
		all->i++;
	}
	while (all->shir - ft_strlen(all->str) > all->checkad && all->shir != 0)
	{
		all->shir--;
		write(1, &all->zero, 1);
		all->exit++;
	}
	free(all->str);
	return (0);
}