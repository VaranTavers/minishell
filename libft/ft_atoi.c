/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 11:24:25 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/02/15 14:00:54 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static int	is_blank(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\f')
		return (1);
	if (c == '\v' || c == '\r')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int i;
	int sign;
	int ret_val;

	sign = 1;
	i = 0;
	ret_val = 0;
	while (is_blank(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1 - (int)str[i] + '+';
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ret_val > (2147483647 - (int)(str[i] - '0')) / 10)
			if (ret_val * 10 + (str[i] - '0') != -2147483648 || sign != -1)
				return ((sign == 1) * (-1));
		ret_val = ret_val * 10 + (int)(str[i] - '0');
		i++;
	}
	return (sign * ret_val);
}
