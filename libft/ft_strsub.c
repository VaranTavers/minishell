/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:12:25 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/12/07 13:25:40 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	ret = NULL;
	if (s != NULL)
	{
		ret = (char *)malloc(len + 1);
		i = 0;
		if (ret != NULL)
		{
			while (i < len)
			{
				ret[i] = s[(size_t)start + i];
				i++;
			}
			ret[i] = 0;
		}
	}
	return (ret);
}
