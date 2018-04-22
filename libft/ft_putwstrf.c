/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstrf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:26:11 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/02/15 13:03:17 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static	void	print_pad(char c, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		write(1, &c, 1);
		j++;
	}
}

int				ft_wprint_width(int *str, t_format *f)
{
	int		l;
	int		rl;

	l = ft_wsprec(str, f);
	rl = ft_wstrleni(str, l);
	if (l < f->f_width && !(f->flag & 4))
	{
		if (f->flag & 2)
			print_pad('0', f->f_width - rl);
		else
			print_pad(' ', f->f_width - rl);
	}
	rl = ft_putwstr(str, l);
	if (l < f->f_width && f->flag & 4)
		print_pad(' ', f->f_width - rl);
	if (rl >= f->f_width)
		return (rl);
	else
		return (f->f_width);
}

static int		to_null(t_format *f)
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

int				ft_putwstrf(va_list *lst, t_format *f)
{
	int		*str;
	int		ret;

	str = va_arg(*lst, int*);
	if (str == 0)
		return (to_null(f));
	ret = ft_wprint_width(str, f);
	return (ret);
}
