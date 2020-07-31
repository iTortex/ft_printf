/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:29:26 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/24 13:47:14 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			*zapoln(t_print *all, int ost)
{
	int i;

	i = 0;
	if ((all->str = ft_calloc(sizeof(char), ost)) == NULL)
		all->error = -1;
	if (all->point == 0)
		all->str[0] = '0';
	while (all->point > 0)
	{
		if (all->point % 16 > 9 && all->point % 16 < 16)
		{
			all->str[i] = all->point % 16 + all->six;
			i++;
		}
		if (all->point % 16 < 10 && all->point % 16 >= 0)
		{
			all->str[i] = all->point % 16 + 48;
			i++;
		}
		all->point /= 16;
	}
	return (0);
}

static void			*rev(t_print *all)
{
	char			*dup;
	int				i;
	int				j;

	i = 0;
	j = ft_strlen(all->str);
	if ((dup = ft_calloc(sizeof(char), j)) == NULL)
		all->error = -1;
	while (all->str[i])
	{
		dup[i] = all->str[i];
		i++;
	}
	i = 0;
	j--;
	while (j >= 0)
	{
		all->str[i] = dup[j];
		i++;
		j--;
	}
	free(dup);
	return (0);
}

void				*transforp(t_print *all)
{
	int				ost;
	long long int	j;

	j = all->point;
	ost = 0;
	all->six = 87;
	while (all->point != 0)
	{
		all->point /= 16;
		ost++;
	}
	all->point = j;
	zapoln(all, ost);
	rev(all);
	return (0);
}
