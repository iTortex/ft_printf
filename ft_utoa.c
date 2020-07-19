/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 16:20:04 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/19 19:34:49 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			schet(unsigned int del, int ch)
{
	while (del)
	{
		ch++;
		del /= 10;
	}
	return (ch);
}

static char			*ravn(char *str1, unsigned int n, int nom)
{
	unsigned int	ch2;

	ch2 = n;
	if (ch2 == 0)
	{
		str1[nom--] = ch2 + '0';
		return (str1);
	}
	while (ch2)
	{
		str1[nom--] = (ch2 % 10) + '0';
		ch2 /= 10;
	}
	return (str1);
}

char				*ft_utoa(unsigned int num)
{
	char			*str;
	int				i;
	unsigned int	ch;
	unsigned int	pol;

	i = 0;
	ch = num;
	if (num <= 0)
		i++;
	i += schet(num, 0);
	str = ft_calloc(i + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	str[i--] = '\0';
	pol = ch;
	if (ch < 0)
	{
		str[0] = '-';
		pol = ch * -1;
	}
	str = ravn(str, pol, i);
	return (str);
}