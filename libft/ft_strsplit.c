/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:25:23 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/11/30 13:25:36 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(char const *str, char c)
{
	int		i;
	int		ret_val;
	char	last;

	last = c;
	i = 0;
	ret_val = 1;
	while (str[i] != 0)
	{
		if (str[i] != c)
			if (last == c)
				ret_val++;
		last = str[i];
		i++;
	}
	return (ret_val);
}

static char		*put_word(char const *str, int i, int *skip, char c)
{
	int		j;
	int		k;
	char	*ret_val;

	j = 0;
	k = 0;
	while (str[i + j] != c && str[i + j] != 0)
		j++;
	ret_val = ft_strnew(j + 1);
	while (k < j)
	{
		ret_val[k] = (char)str[i + k];
		k++;
	}
	*skip = j;
	ret_val[j] = 0;
	return (ret_val);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**ret_val;
	int		num;
	int		i;
	int		j;
	int		skip;

	if (str == NULL)
		return (NULL);
	num = word_count(str, c);
	ret_val = (char**)ft_memalloc(sizeof(*ret_val) * num);
	if (ret_val != NULL)
	{
		i = 0;
		j = 0;
		while (i < num - 1)
		{
			while (str[j] == c)
				j++;
			ret_val[i] = put_word(str, j, &skip, c);
			j += skip;
			i++;
		}
		ret_val[num - 1] = 0;
	}
	return (ret_val);
}
