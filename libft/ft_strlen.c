/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:21:50 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/02/15 14:01:50 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

size_t	ft_strlen(const char *str)
{
	size_t		length;

	length = 0;
	while (*(str + length) != 0)
	{
		length++;
	}
	return (length);
}
