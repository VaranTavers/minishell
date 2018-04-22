/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:57:59 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/11/28 18:09:18 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ret_val;
	int		src_len;
	int		i;

	src_len = 0;
	while (src[src_len] != 0)
		src_len++;
	i = 0;
	if ((ret_val = (char*)malloc(sizeof(*ret_val) * src_len + 1)))
	{
		while (i <= src_len)
		{
			ret_val[i] = src[i];
			i++;
		}
		return (ret_val);
	}
	return (0);
}
