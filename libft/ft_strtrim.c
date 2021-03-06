/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:41:27 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/11/30 11:51:08 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	int		l[3];

	if (s == NULL)
		return (NULL);
	l[0] = 0;
	l[1] = ft_strlen(s) - 1;
	while ((s[l[1]] == ' ' || s[l[1]] == '\n' || s[l[1]] == '\t') && l[1] > 0)
		l[1]--;
	while ((s[l[0]] == ' ' || s[l[0]] == '\n' || s[l[0]] == '\t')
			&& l[0] <= l[1])
		l[0]++;
	l[2] = 0;
	ret = (char *)malloc(l[1] - l[0] + 2);
	if (ret != NULL)
	{
		while (l[2] <= l[1] - l[0])
		{
			ret[l[2]] = s[l[0] + l[2]];
			l[2]++;
		}
		ret[l[2]] = 0;
	}
	return (ret);
}
