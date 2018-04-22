/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:49:13 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/02/15 14:00:39 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p_src;
	unsigned char	*p_dst;
	size_t			i;

	p_src = (unsigned char*)src;
	p_dst = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		*(p_dst + i) = *(p_src + i);
		i++;
	}
	return (dst);
}
