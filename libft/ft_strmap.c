/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:53:13 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/12/12 19:48:43 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = NULL;
	if (s != NULL)
	{
		while (s[i] != 0)
			i++;
		ret = (char*)malloc(i + 1);
		if (ret != NULL)
		{
			i = 0;
			while (s[i] != 0)
			{
				ret[i] = f(s[i]);
				i++;
			}
			ret[i] = 0;
		}
	}
	return (ret);
}
