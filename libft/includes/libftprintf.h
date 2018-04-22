/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:00:54 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/02/15 14:03:35 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <wchar.h>

typedef struct	s_format
{
	char	flag;
	int		f_width;
	int		precision;
	char	conv[4];
}				t_format;

int				ft_atoi(const char *str);

void			*ft_memcpy(void *dest, const void *src, size_t n);

void			ft_putchar(char c);

void			ft_putstr(char const *str);

size_t			ft_strlen(const char *str);

void			update_conv(int *tb, t_format *f, char c);

int				ft_wstrleni(int *str, int len);

int				ft_wsprec(int *str, t_format *f);

int				ft_putwstr(int *str, int len);

void			ft_putcharr(char *str, int i);

void			ft_wchar1(char *str, wchar_t wc, int *len);

int				do_flags(va_list *lst, char *format, int *printed);

int				do_conv(va_list *lst, t_format *f);

int				ft_print_width(char *str, t_format *f);

int				ft_printf(const char *format, ...);

int				ft_percent(va_list *lst, t_format *f);

int				ft_dn(va_list *lst, t_format *f);

int				ft_putbinf(va_list *lst, t_format *f);

int				ft_putwcharf(va_list *lst, t_format *f);

int				ft_putnbrf(va_list *lst, t_format *f);

int				ft_putoctf(va_list *lst, t_format *f);

int				ft_putnpstrf(va_list *lst, t_format *f);

int				ft_putwstrf(va_list *lst, t_format *f);

int				ft_putunbrf(va_list *lst, t_format *f);

int				ft_puthexf(va_list *lst, t_format *f);

int				ft_putbinf(va_list *lst, t_format *f);

int				ft_putcharf(va_list *lst, t_format *f);

int				ft_putexpf(va_list *lst, t_format *f);

int				ft_putfloatf(va_list *lst, t_format *f);

int				ft_putptrf(va_list *lst, t_format *f);

int				ft_putstrf(va_list *lst, t_format *f);

#endif
