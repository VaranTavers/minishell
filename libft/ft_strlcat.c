/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 17:45:27 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/11/30 11:28:25 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		dst_l;

	dst_l = ft_strlen(dst);
	if (size != 0 && dst_l < size)
	{
		i = 0;
		while (dst_l + i < size - 1 && src[i] != 0)
		{
			dst[dst_l + i] = src[i];
			i++;
		}
		dst[dst_l + i] = 0;
		return (dst_l + ft_strlen(src));
	}
	return (ft_strlen(src) + size);
}
