/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:08:04 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/02/15 13:45:41 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int		do_modifiers(va_list *lst, char *format, t_format *f, int *printed)
{
	int		j;
	int		modif[127];

	j = 0;
	while (j < 127)
	{
		modif[j] = 0;
		j++;
	}
	j = 0;
	while (format[j] == 'h' || format[j] == 'l' ||
			format[j] == 'j' || format[j] == 'z')
	{
		modif[(int)format[j]]++;
		j++;
	}
	update_conv((int*)modif, f, format[j]);
	if (format[j] != '\0')
	{
		*printed += do_conv(lst, f);
		return (j + 1);
	}
	return (j);
}

void	get_arg(va_list *lst, t_format *f, char *format, int a)
{
	int		tmp;

	if (a == 0)
	{
		f->f_width = va_arg(*lst, int);
		if (f->f_width < 0)
		{
			f->flag |= 4;
			f->f_width *= -1;
		}
		if ((tmp = ft_atoi(format)) || (format[0] >= '0' && format[0] <= '9'))
			f->f_width = tmp;
	}
	else
	{
		f->precision = va_arg(*lst, int);
		if (f->precision < 0)
		{
			f->flag &= 0xDF;
			f->precision = 0;
		}
		tmp = ft_atoi(format);
		if (format[0] >= '0' && format[0] <= '9')
			f->precision = tmp;
	}
}

int		do_prec(va_list *lst, char *format, t_format *f, int *printed)
{
	int		i;

	i = 0;
	f->precision = 0;
	if (format[i] == '.')
	{
		f->flag |= 32;
		i++;
		f->precision = ft_atoi(format + i);
		while (format[i] >= '0' && format[i] <= '9')
			i++;
		if (format[i] == '*')
			get_arg(lst, f, format + 1, 1);
		while ((format[i] >= '0' && format[i] <= '9') || format[i] == '*')
			i++;
	}
	return (i + do_modifiers(lst, format + i, f, printed));
}

int		do_fw_prec(va_list *lst, char *format, t_format *f, int *printed)
{
	int		i;

	i = 0;
	f->f_width = ft_atoi(format);
	while ((format[i] >= '0' && format[i] <= '9'))
		i++;
	if (format[i] == '*')
		get_arg(lst, f, format + 1, 0);
	while ((format[i] >= '0' && format[i] <= '9') || format[i] == '*')
		i++;
	return (i + do_prec(lst, format + i, f, printed));
}

int		do_flags(va_list *lst, char *format, int *printed)
{
	t_format	*f;
	int			i;
	int			ret;

	f = (t_format*)malloc(sizeof(*f));
	f->flag = 0;
	i = 0;
	while (format[i] == '#' || (format[i] == '0') ||
			format[i] == '-' || format[i] == '+' || format[i] == ' ')
	{
		if (format[i] == '#')
			f->flag = f->flag | 1;
		if (format[i] == '0')
			f->flag = f->flag | 2;
		if (format[i] == '-')
			f->flag = f->flag | 4;
		if (format[i] == '+')
			f->flag = f->flag | 8;
		if (format[i] == ' ')
			f->flag = f->flag | 16;
		i++;
	}
	ret = do_fw_prec(lst, format + i, f, printed);
	free(f);
	return (ret + i);
}
