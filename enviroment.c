/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:13:17 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/04/15 17:54:53 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_list		*init_environ(void)
{
	int			i;
	extern char	**environ;
	t_list		*ret;
	t_pair		*toadd;

	i = 0;
	ret = NULL;
	while (environ[i])
	{
		toadd = pair_from_environ(environ[i]);
		ft_lstadd(&ret, ft_lstelem(toadd, sizeof(*toadd)));
		i++;
	}
	return (ret);
}

char		*get_env(t_list *env, const char *tofind)
{
	size_t	l;
	t_list	*p;
	t_pair	*pair;

	p = env;
	l = 0;
	while (ft_isalnum(tofind[l]) || tofind[l] == '_')
		l++;
	while (p != NULL)
	{
		pair = (t_pair*)(p->content);
		if (l == ft_strlen(pair->key) && ft_strnequ(pair->key, tofind, l))
			return (pair->value);
		p = p->next;
	}
	return ("");
}

int			set_env(t_list *env, const char *tofind, const char *toset)
{
	size_t	l;
	t_list	*p;
	t_pair	*pair;

	p = env;
	l = 0;
	while (ft_isalnum(tofind[l]) || tofind[l] == '_')
		l++;
	while (p != NULL)
	{
		pair = (t_pair*)(p->content);
		if (l == ft_strlen(pair->key) && ft_strnequ(pair->key, tofind, l))
		{
			ft_strdel(&(pair->value));
			pair->value = ft_strdup(toset);
			return (1);
		}
		p = p->next;
	}
	return (0);
}

char		*replace_env(t_list *env, const char *input)
{
	char	*found;
	char	*ret;
	char	*newret;
	char	*tmp;
	int		tav;

	ret = ft_strdup(input);
	while ((found = ft_smartsearch(ret, '$', 1)) && (ft_isalnum(found[1]) ||
			found[1] == '_'))
	{
		tav = found - ret;
		newret = ft_strnew(tav);
		ft_strncpy(newret, ret, tav);
		found++;
		tmp = ft_strjoin(newret, get_env(env, found));
		ft_strdel(&newret);
		while (ft_isalnum(*found) || *found == '_')
			found++;
		newret = ft_strjoin(tmp, found);
		ft_strdel(&ret);
		ft_strdel(&tmp);
		ret = newret;
	}
	return (ret);
}
