/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequotify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 18:07:11 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/04/18 16:30:52 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_dequotify_av(char **av)
{
	int		i;
	char	*old;

	i = 1;
	while (av[i])
	{
		old = av[i];
		av[i] = ft_dequotify(av[i]);
		ft_strdel(&old);
		i++;
	}
}

void	ft_deqcopy(char *dst, const char *src)
{
	char	last;
	int		l;
	int		i;

	l = 0;
	i = 0;
	last = 0;
	while (src[i] != '\0')
	{
		if (last == '\\' ||
				(src[i] != '\'' && src[i] != '\"' && src[i] != '\\'))
		{
			dst[l] = src[i];
			l++;
		}
		last = src[i];
		i++;
	}
}

char	*ft_dequotify(const char *src)
{
	char	last;
	int		l;
	int		i;
	char	*ret;

	l = 0;
	i = 0;
	last = 0;
	while (src[i] != '\0')
	{
		if (last == '\\' ||
				(src[i] != '\'' && src[i] != '\"' && src[i] != '\\'))
			l++;
		last = src[i];
		i++;
	}
	ret = ft_strnew(l);
	if (ret != NULL)
		ft_deqcopy(ret, src);
	return (ret);
}
