/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 14:17:07 by amarcele          #+#    #+#             */
/*   Updated: 2020/07/20 20:22:58 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_print
{
	char			prcnt;
	int				id;
	int				checkforminus;
	int				exit;
	int				shir;
	char			dot;
	char			star;
	char			minus;
	char			zero;
	long long int	point;
	unsigned int	six;
	unsigned int	wrks;
	int				i;
	int				first;
	char			*str;
	char			sym;
	int				afterdot;
	int				checkad;
}					t_print;

void				*transforx(t_print *all, const char *format);
void				*transforp(t_print *all);
void				*writeforprcnt(t_print *all, const char *format);
void				*writeforp(t_print *all, va_list *factor);
char				*ft_utoa(unsigned int num);
void				*writeforu(t_print *all, va_list *factor);
void				*writeforxx(const char *format, t_print *all,
va_list *factor);
void				*writeforc(t_print *all, va_list *format);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_itoa(int num);
void				*writeforid(t_print *all, va_list *factor);
void				*writefors(t_print *all, va_list *factor);
void				*width(const char *format, t_print *all, va_list *factor);
void				*workwithdot(const char *format, t_print *all,
va_list *factor);
int					ft_atoi(const char *str);
int					ft_strlen(const char *str);

#endif
