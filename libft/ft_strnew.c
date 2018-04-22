/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:18:18 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/11/30 13:23:36 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;
	size_t	i;

	ret = (char *)malloc(size + 1);
	if (ret != NULL)
	{
		i = 0;
		while (i < size + 1)
		{
			ret[i] = 0;
			i++;
		}
	}
	return (ret);
}
