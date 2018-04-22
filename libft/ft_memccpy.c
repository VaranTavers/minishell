/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:49:13 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/12/16 15:53:43 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*p_src;
	unsigned char	*p_dst;
	size_t			i;

	p_src = (unsigned char*)src;
	p_dst = (unsigned char*)dst;
	i = 0;
	while (i < n && *(p_src + i) != (unsigned char)c)
	{
		*(p_dst + i) = *(p_src + i);
		i++;
	}
	if (*(p_src + i) == (unsigned char)c)
	{
		*(p_dst + i) = *(p_src + i);
		i++;
		return ((void *)(p_dst + i));
	}
	else
		return (NULL);
}
