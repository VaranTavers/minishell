/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 13:53:29 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/11/28 18:07:00 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	real_c;

	real_c = (char)c;
	i = 0;
	while (s[i] != 0)
		i++;
	while (i >= 0 && s[i] != real_c)
		--i;
	if (i < 0)
		return (0);
	return ((char*)&s[i]);
}
