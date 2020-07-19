/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:05:36 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/13 17:05:14 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int i;

	if (dst == src)
		return (0);
	i = ft_strlen(src);
	while (size > 1 && *src != '\0')
	{
		*dst++ = *src++;
		size--;
	}
	if (size != 0)
		*dst = '\0';
	return (i);
}
