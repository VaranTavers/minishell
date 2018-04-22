/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 17:45:53 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/04/15 14:18:01 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_pair		*new_pair(const char *key, const char *value)
{
	t_pair	*ret;

	ret = ft_memalloc(sizeof(*ret));
	ret->key = ft_strdup(key);
	ret->value = ft_strdup(value);
	return (ret);
}

t_pair		*pair_from_environ(const char *env)
{
	t_pair	*ret;
	int		i;

	ret = ft_memalloc(sizeof(*ret));
	i = ft_strchr(env, '=') - env;
	ret->key = ft_strnew(i);
	ft_strncpy(ret->key, env, i);
	ret->value = ft_strdup(env + i + 1);
	return (ret);
}

void		free_pair(void *p, size_t s)
{
	t_pair	*pp;

	s = 0;
	pp = (t_pair*)p;
	free(pp->key);
	free(pp->value);
	free(pp);
}
