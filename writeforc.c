/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeforc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:51:50 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/12 19:24:08 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*writeforc(t_print *all, va_list *factor)
{
	if (all->minus != '-')
	{
		all->sym = va_arg(*factor, int);
		if (all->shir != 0)
		{
			all->shir--;
			while (all->shir != 0)
			{
				write(1, " ", 1);
				all->shir--;
			}
		}
		write(1, &all->sym, 1);
	}
	if (all->minus == '-')
	{
		all->sym = va_arg(*factor, int);
		write(1, &all->sym, 1);
		if (all->shir != 0)
		{
			all->shir--;
			while (all->shir != 0)
			{
				write(1, " ", 1);
				all->shir--;
			}
		}
	}
	all->i++;
	return (0);
}