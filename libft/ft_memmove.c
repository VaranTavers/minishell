/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:49:13 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/12/12 19:51:11 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (n > 0)
	{
		i = 0;
		if (src > dst)
			while (i < n)
			{
				*((char*)dst + i) = *((char*)src + i);
				i++;
			}
		else if (src != dst)
		{
			n--;
			while (n > 0)
			{
				*((char*)dst + n) = *((char*)src + n);
				n--;
			}
			*((char*)dst) = *((char*)src);
		}
	}
	return (dst);
}
