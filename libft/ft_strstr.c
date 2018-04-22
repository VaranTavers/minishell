/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 13:53:29 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/11/28 19:06:46 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	if (*little == 0)
		return ((char*)big);
	while (big[i] != 0)
	{
		j = 0;
		result = (char *)&big[i];
		while (little[j] != 0 && big[i + j] == little[j])
			j++;
		if (little[j] == 0)
			return (result);
		i++;
	}
	return (0);
}
