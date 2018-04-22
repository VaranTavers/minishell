/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:57:11 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/11/23 14:14:25 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;
	unsigned char	actual_c;

	p = (unsigned char*)s;
	i = 0;
	actual_c = (unsigned char)c;
	while (i < n)
	{
		if (*(p + i) == actual_c)
			return (p + i);
		i++;
	}
	return (NULL);
}
