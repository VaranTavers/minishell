/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:00:36 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/04/20 15:53:23 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <sys/stat.h>

char	*prepare_path(t_list *env, char *av)
{
	char	*puffer;
	char	*ret;

	if (ft_strequ(av, "-"))
		return (ft_strdup(get_env(env, "OLDPWD")));
	if (av == 0 || av[0] == '\0')
		return (ft_strdup(get_env(env, "HOME")));
	if (av[0] == '~')
		return (ft_strjoin(get_env(env, "HOME"), av + 1));
	if (av[0] != '/')
	{
		puffer = ft_strjoin("/", av);
		ret = ft_strjoin(get_env(env, "PWD"), puffer);
		ft_strdel(&puffer);
		return (ret);
	}
	return (ft_strdup(av));
}

int		do_change(t_list *env, char *path)
{
	int		l;
	t_pair	*toadd;
	char	*newpath;

	l = ft_strlen(path) + 1;
	newpath = ft_strnew(l + 1);
	if (chdir(path) == 0 && getcwd(newpath, l) != NULL)
	{
		if (!set_env(env, "OLDPWD", get_env(env, "PWD")))
			ft_lstpushback(&env, ft_lstelem(new_pair("OLDPWD",
							get_env(env, "PWD")), sizeof(t_pair*)));
		if (!set_env(env, "PWD", newpath))
		{
			toadd = new_pair("PWD", newpath);
			ft_lstpushback(&env, ft_lstelem(toadd, sizeof(t_pair*)));
		}
		ft_strdel(&newpath);
	}
	else
	{
		ft_putstr_fd("cd: unable to change pwd\n", 2);
		ft_strdel(&newpath);
		return (1);
	}
	return (0);
}

int		ft_cd(t_list *env, char **av)
{
	char			*path;
	struct stat		*st;
	int				ret;

	ret = 0;
	st = (struct stat *)malloc(sizeof(struct stat));
	path = prepare_path(env, av[1]);
	if (lstat(path, st) != 0)
	{
		ft_putstr_fd("cd: unable to open directory \"", 2);
		ft_putstr_fd(av[1], 2);
		ft_putstr_fd("\"\n", 2);
		ret = 1;
	}
	else
		ret = do_change(env, path);
	free(st);
	ft_strdel(&path);
	return (ret);
}
