/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 13:53:29 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/12/07 11:47:27 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	real_c;

	real_c = (char)c;
	i = 0;
	while (s[i] != 0 && s[i] != real_c)
		i++;
	if (s[i] == 0 && c != 0)
		return (0);
	return ((char*)&s[i]);
}
