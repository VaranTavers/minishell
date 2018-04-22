/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 10:24:00 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/02/15 12:45:13 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int		ft_size(int c)
{
	if (c <= 0x7F)
		return (1);
	if (c <= 0x7FF)
		return (2);
	if (c <= 0xFFFF)
		return (3);
	if (c <= 0x1FFFFF)
		return (4);
	if (c <= 0x3FFFFFF)
		return (5);
	else
		return (6);
}

int		ft_wstrleni(int *str, int len)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if (!str)
		return (6);
	while (i < len)
	{
		ret += ft_size(str[i]);
		i++;
	}
	return (ret);
}

int		ft_wsprec(int *str, t_format *f)
{
	int		i;
	int		j;

	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		j += ft_size(str[i]);
		if (j >= f->precision && (f->flag & 32))
		{
			if (j == f->precision)
				return (i + 1);
			else
				return (i);
		}
		i++;
	}
	return (i);
}

int		ft_putwstr(int *str, int len)
{
	int		i;
	char	*cstr;
	int		c_len;
	int		ret;

	cstr = (char*)malloc(sizeof(*cstr) * 10);
	i = 0;
	ret = 0;
	while (i < len)
	{
		c_len = 0;
		ft_wchar1(cstr, str[i], &c_len);
		ret += c_len;
		ft_putcharr(cstr, c_len);
		i++;
	}
	free(cstr);
	return (ret);
}
