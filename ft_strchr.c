/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:50:38 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/10 14:43:59 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *str, int ch)
{
	int i;

	i = 0;
	while (str[i] != ch && str[i] != '\0')
		i++;
	if (str[i] == ch)
		return (&((char *)str)[i]);
	else
		return (NULL);
}
