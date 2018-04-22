/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:26:11 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/02/14 12:06:45 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int		ft_dn(va_list *lst, t_format *f)
{
	char	*towrite;
	int		ret;

	if (*lst == 0)
		return (0);
	towrite = (char *)malloc(sizeof(*towrite) * 2);
	towrite[1] = '\0';
	if (f->conv[0] != 'j' && f->conv[0] != 'z' && f->conv[0] != 'l' &&
			f->conv[0] != 'h')
		towrite[0] = f->conv[0];
	else if (f->conv[1] != 'j' && f->conv[1] != 'z' && f->conv[1] != 'l' &&
			f->conv[1] != 'h')
		towrite[0] = f->conv[1];
	else
		towrite[0] = f->conv[2];
	ret = ft_print_width(towrite, f);
	free(towrite);
	return (ret);
}
