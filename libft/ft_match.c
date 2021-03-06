/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 10:15:13 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/12/16 16:54:15 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_match(char *s1, char *s2)
{
	if (*s1 == 0 && *s2 == 0)
		return (1);
	if (*s1 == 0 && *s2 == '*')
		return (ft_match(s1, s2 + 1));
	if (*s2 == '*')
	{
		return (ft_match(s1, s2 + 1) || ft_match(s1 + 1, s2));
	}
	if (*s1 == 0 || *s2 == 0)
		return (0);
	if (*s1 == *s2)
		return (ft_match(s1 + 1, s2 + 1));
	return (0);
}
