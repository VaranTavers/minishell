/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:27:44 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/04/20 17:18:56 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*try_path(t_list *env, char *path, char *cmd)
{
	char		*a;
	char		*b;

	if (cmd[0] == '/')
		b = ft_strdup(cmd);
	else if (cmd[0] == '~')
		b = ft_strjoin(get_env(env, "HOME"), cmd + 1);
	else
	{
		a = ft_strjoin(path, "/");
		b = ft_strjoin(a, cmd);
		ft_strdel(&a);
	}
	if (b != NULL)
	{
		if (access(b, X_OK) == 0)
			return (b);
		ft_strdel(&b);
	}
	return (NULL);
}

char	**ft_stringify_env(t_list *env)
{
	int		i;
	t_pair	*a;
	t_list	*p;
	char	**ret;
	char	*tmp;

	p = env;
	ret = (char**)malloc(sizeof(*ret) * (ft_lstsize(env) + 1));
	i = 0;
	if (ret != NULL)
	{
		while (p != NULL)
		{
			a = (t_pair*)(p->content);
			tmp = ft_strjoin(a->key, "=");
			ret[i] = ft_strjoin(tmp, a->value);
			ft_strdel(&tmp);
			i++;
			p = p->next;
		}
		ret[i] = 0;
	}
	return (ret);
}

int		do_exec(char *path, char **av, t_list *env)
{
	char	**envs;
	pid_t	cid;
	int		ret;
	int		status;

	status = 0;
	envs = ft_stringify_env(env);
	cid = fork();
	if (cid == 0)
	{
		if ((ret = execve(path, av, envs)) < 0)
			exit(92);
	}
	else if (cid > 0)
	{
		waitpid(cid, &status, 0);
		ret = status;
	}
	else
	{
		ft_putstr_fd("unable to fork\n", 2);
		ret = 1;
	}
	free_split(&envs);
	return (ret);
}

int		do_local(t_list *env, char **av, int *ret)
{
	char	*ered;
	int		found;

	found = 0;
	ered = try_path(env, get_env(env, "PWD"), av[0]);
	if (ered != NULL && ft_strlen(get_env(env, "PWD")) > 0)
	{
		*ret = do_exec(ered, av, env);
		ft_strdel(&ered);
		found = 1;
	}
	return (found);
}

int		ft_path(t_list *env, char **av, int *ret)
{
	char	**paths;
	char	*ered;
	int		i;
	int		found;

	if (av[0][0] != '.' || av[0][1] != '/')
	{
		found = 0;
		paths = ft_strsplit(get_env(env, "PATH"), ':');
		i = 0;
		while (paths[i] && (ered = try_path(env, paths[i], av[0])) == 0)
			i++;
		if (ered != NULL && paths[i] != NULL && ft_strlen(paths[i]) > 0)
		{
			*ret = do_exec(ered, av, env);
			ft_strdel(&ered);
			found = 1;
		}
		free_split(&paths);
		return (found);
	}
	else
		return (do_local(env, av, ret));
}
