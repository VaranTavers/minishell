/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 17:28:37 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/11/28 18:09:45 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t		i;
	size_t		dest_l;

	dest_l = 0;
	while (dest[dest_l] != 0)
		dest_l++;
	i = 0;
	while (src[i] != 0 && i < n)
	{
		dest[dest_l + i] = src[i];
		i++;
	}
	dest[dest_l + i] = 0;
	return (dest);
}
