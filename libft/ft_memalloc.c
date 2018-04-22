/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:18:18 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/11/30 10:23:10 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ret;
	size_t	i;
	char	*p;

	ret = malloc(size);
	p = (char *)ret;
	if (p != NULL)
	{
		i = 0;
		while (i < size)
		{
			*(p + i) = 0;
			i++;
		}
	}
	return (ret);
}
