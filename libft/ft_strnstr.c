/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 13:53:29 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/11/28 19:07:18 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char		*result;
	size_t		i;
	size_t		j;

	i = 0;
	if (*little == 0)
		return ((char*)big);
	while (big[i] != 0 && i < len)
	{
		j = 0;
		result = (char*)&big[i];
		while (little[j] != 0 && big[i + j] == little[j] && i + j < len)
			j++;
		if (little[j] == 0)
			return (result);
		i++;
	}
	return (0);
}
