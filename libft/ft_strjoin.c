/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:34:34 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/12/12 20:13:17 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	l[3];

	ret = NULL;
	if (s1 == NULL || s2 == NULL)
		return (ret);
	l[0] = ft_strlen(s1);
	l[1] = ft_strlen(s2);
	ret = (char *)malloc(l[0] + l[1] + 1);
	if (ret != NULL)
	{
		l[2] = 0;
		while (l[2] < l[0])
		{
			ret[l[2]] = s1[l[2]];
			l[2]++;
		}
		while (l[2] < l[0] + l[1])
		{
			ret[l[2]] = s2[l[2] - l[0]];
			l[2]++;
		}
		ret[l[2]] = 0;
	}
	return (ret);
}
