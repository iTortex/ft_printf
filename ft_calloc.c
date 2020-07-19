/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 18:58:02 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/12 16:38:14 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char *mem;
	int i;

	i = 0;
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	mem = malloc(size * nmemb);
	if (mem == NULL)
		return (NULL);
	while (nmemb != 0)
	{
		mem[i] = '\0';
		i++;
		nmemb--;
	}
	return (mem);
}
