/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 18:29:30 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/10 19:28:44 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*width(const char *format, t_print *all)
{
	char *ptr;
	ptr = (&((char *)format)[all->i]);
	all->shir = ft_atoi(ptr);
	while(format[all->i] >= '1' && format[all->i] <= '9')
		all->i++;
	return (0);
}