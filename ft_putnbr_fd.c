/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 17:08:44 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/05 15:24:21 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_putnbr_fd(int n, int fd)
{
	char			ch;
	unsigned int	i;

	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	i = n;
	if (i >= 10)
	{
		ft_putnbr_fd(i / 10, fd);
		ch = (i % 10) + '0';
		write(fd, &ch, 1);
	}
	if (i < 10)
	{
		ch = i + '0';
		write(fd, &ch, 1);
	}
}
