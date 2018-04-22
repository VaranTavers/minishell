/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 17:17:37 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/11/28 17:16:18 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		dest_l;

	dest_l = 0;
	while (dest[dest_l] != 0)
		dest_l++;
	i = 0;
	while (src[i] != 0)
	{
		dest[dest_l + i] = src[i];
		i++;
	}
	dest[dest_l + i] = 0;
	return (dest);
}
