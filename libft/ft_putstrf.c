/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:26:11 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/02/15 12:28:44 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static int	to_null(t_format *f)
{
	int		ret;
	char	*str;

	str = (char*)malloc(sizeof(*str) * 10);
	ft_memcpy(str, "(null)", 7);
	if (f->precision < 6 && f->flag & 32)
		str[f->precision] = '\0';
	ret = ft_print_width(str, f);
	free(str);
	return (ret);
}

int			ft_putstrf(va_list *lst, t_format *f)
{
	int		ret;
	char	*ki;
	char	*be;

	if (f->conv[0] == 'l')
		return (ft_putwstrf(lst, f));
	be = va_arg(*lst, char*);
	if (be == 0)
		return (to_null(f));
	ret = ft_strlen(be);
	if (ret > f->precision && (f->precision != 0 || f->flag & 32))
		ret = f->precision;
	ki = (char*)malloc(sizeof(*ki) * (ret + 1));
	ft_memcpy(ki, be, ret);
	ki[ret] = '\0';
	ret = ft_print_width(ki, f);
	free(ki);
	return (ret);
}
