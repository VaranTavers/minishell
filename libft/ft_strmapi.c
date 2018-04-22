/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:53:13 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/12/12 19:47:15 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

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
				ret[i] = f(i, s[i]);
				i++;
			}
			ret[i] = 0;
		}
	}
	return (ret);
}
