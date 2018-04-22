/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smartsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 13:25:48 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/04/14 14:09:50 by ztasnadi         ###   ########.fr       */
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

static int		word_count(char *str, char c)
{
	int		i;
	int		ret_val;
	int		last;

	last = -1;
	i = 0;
	ret_val = 2;
	while (str[i] != 0)
	{
		if (str[i] == '\"' || str[i] == '\'')
			i += skip_to_end(str + i);
		if (str[i] == '\\')
			i += 2;
		if (str[i] != c)
			if (last != -1 && str[last] == c)
			{
				ret_val++;
				if (i != 0)
					str[last] = 0;
			}
		last = i;
		i++;
	}
	return (ret_val);
}

static char		*put_word(char *str, int i, int *skip)
{
	int		j;
	int		k;
	char	*ret_val;

	j = 0;
	k = 0;
	while (str[i + j] != 0)
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

char			**ft_smartsplit(char *str, char c)
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
			while (str[j] == c || str[j] == 0)
				j++;
			ret_val[i] = put_word(str, j, &skip);
			j += skip;
			i++;
		}
		ret_val[num - 1] = 0;
	}
	return (ret_val);
}
