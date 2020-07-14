/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 14:17:07 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/14 16:46:21 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
#include <stdio.h>

typedef struct	s_print
{
	int exit;
	unsigned int shir;
	char dot;
	char star;
	char minus;
	char zero;
	long long int point;
	unsigned int six;
	unsigned int wrks;
	unsigned int i;
	unsigned int first;
	char *str;
	char sym;
	unsigned int afterdot;
	unsigned int checkad;
}				t_print;

void	*writeforp(t_print *all, va_list *factor);
char	*ft_utoa(unsigned int num);
void	*writeforu(t_print *all, va_list *factor);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*writeforxX(const char *format, t_print *all, va_list *factor);
void	*writeforc(t_print *all, va_list *format);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa(int num);
void	*writeforid(t_print *all, va_list *factor);
void	*writefors(t_print *all, va_list *factor);
void	*width(const char *format, t_print *all, va_list *factor);
void	*workwithdot(const char *format, t_print *all, va_list *factor);
char	*ft_strchr(const char *str, int ch);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *str);

#endif