/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smartsearch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:35:16 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/04/14 17:59:50 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int		skip_to_end(char *str)
{
	int		i;
	char	nyit;

	i = 1;
	nyit = str[0];
	while ((str[i] != nyit && str[i - 1] != '\\' && str[i] != 0))
		i++;
	return (i);
}

char			*ft_smartsearch(char *str, char c, int level)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if ((str[i] == '\"' && level > 1) || (str[i] == '\'' && level > 0))
			i += skip_to_end(str + i);
		if (str[i] == '\\')
			i += 1 + (str[i + 1] != 0);
		if (str[i] == c)
			return (str + i);
		++i;
	}
	return (0);
}
