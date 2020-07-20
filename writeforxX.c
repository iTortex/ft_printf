/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeforxX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:48:09 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/20 18:35:44 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void afsmsh(t_print *all)
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

static void	*minushere(t_print *all)
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
	return (0);
}

static void *minusnothere(t_print *all)
{
	if (!all->afterdot || all->afterdot < ft_strlen(all->str))
		all->afterdot = ft_strlen(all->str);
	if (all->afterdot < all->shir)
		afsmsh(all);
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

static void	forif(t_print *all, const char *format)
{
	if (all->wrks == 0)	
		all->str = "0";
	transforx(all, format);
	if (all->afterdot != 0)
		all->checkad = all->afterdot;
	if (all->minus != '-')
		minusnothere(all);
	if (all->minus == '-')
		minushere(all);
	if (all->shir <= ft_strlen(all->str))
		all->shir = 0;
}

void	*writeforxX(const char *format, t_print *all, va_list *factor)
{
	all->wrks = va_arg(*factor, unsigned int);
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
	forif(all, format);
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