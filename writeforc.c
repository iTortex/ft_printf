/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeforc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:51:50 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/16 14:55:20 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void *minushere(t_print *all)
{
	write(1, &all->sym, 1);
	if (all->shir != 0)
	{
		all->shir--;
		while (all->shir != 0)
		{
			write(1, " ", 1);
			all->shir--;
			all->exit++;
		}
	}
	return (0);
}

void	*writeforc(t_print *all, va_list *factor)
{
	all->sym = va_arg(*factor, int);
	if (all->minus != '-')
	{
		if (all->shir != 0)
		{
			all->shir--;
			while (all->shir != 0)
			{
				write(1, " ", 1);
				all->shir--;
				all->exit++;
			}
		}
		write(1, &all->sym, 1);
		all->exit++;
	}
	if (all->minus == '-')
		minushere(all);
	all->i++;
	return (0);
}