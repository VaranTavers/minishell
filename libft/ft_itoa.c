/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 11:07:43 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/12/07 13:38:25 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	num_len(int nb)
{
	int		ret;

	ret = 1;
	if (nb < 0)
		ret++;
	nb /= 10;
	while (nb != 0)
	{
		ret++;
		nb /= 10;
	}
	return (ret);
}

static int	s_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

char		*ft_itoa(int nb)
{
	char	*c;
	int		i;
	int		l;

	l = num_len(nb);
	c = (char *)malloc(l + 1);
	i = 0;
	if (c != NULL)
	{
		c[l] = 0;
		l--;
		if (nb < 0)
			c[0] = '-';
		if (nb < 0)
			i++;
		while (i <= l)
		{
			c[l] = s_abs(nb % 10) + '0';
			nb /= 10;
			l--;
		}
	}
	return (c);
}
