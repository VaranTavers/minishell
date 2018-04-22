/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:31:55 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/12/12 19:52:39 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	actual_c;
	size_t			i;

	p = (unsigned char*)b;
	actual_c = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		*(p + i) = actual_c;
		i++;
	}
	return (b);
}
