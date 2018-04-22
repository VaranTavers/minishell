/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpret.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 13:21:31 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/04/20 15:50:12 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char		*g_internal_names[6] =
{"cd", "echo", "env", "exit", "setenv", "unsetenv"};

int			(*g_internals[6])(t_list *env, char **av) =
{&ft_cd, &ft_echo, &ft_env, &ft_exit, &ft_setenv, &ft_unsetenv};

const int	g_internals_count = 6;

void		free_split(char ***av)
{
	char	**p;
	int		i;

	if (*av != NULL)
	{
		p = *av;
		i = 0;
		while (p[i] != 0)
		{
			free(p[i]);
			i++;
		}
		free(*av);
		*av = 0;
	}
}

int			ft_internal(t_list *env, char **av, int *ret)
{
	int		left;
	int		right;
	int		mid;

	left = 0;
	right = g_internals_count;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (ft_strequ(av[0], g_internal_names[mid]))
		{
			*ret = g_internals[mid](env, av);
			return (1);
		}
		else if (ft_strcmp(av[0], g_internal_names[mid]) < 0)
			right = mid;
		else
			left = mid + 1;
	}
	return (0);
	env = 0;
}

int			ft_syntax(t_list *env, char **av, int *ret)
{
	if (av == 0)
		*ret = 0;
	return (0);
	env = 0;
}

void		ft_apply_env(t_list *env, char **av)
{
	int		i;
	char	*old;

	i = 1;
	while (av[i])
	{
		old = av[i];
		av[i] = replace_env(env, av[i]);
		ft_strdel(&old);
		i++;
	}
}

int			ft_interpret(char **str, t_list *env)
{
	char	**av;
	int		ret;

	av = ft_smartsplit(*str, ' ');
	ft_apply_env(env, av);
	ft_dequotify_av(av);
	ret = 1;
	ft_strdel(str);
	if (!ft_internal(env, av, &ret))
		if (!ft_path(env, av, &ret))
			if (!ft_syntax(env, av, &ret))
			{
				ft_putstr_fd(av[0], 2);
				ft_putstr_fd(": is not an internal or external command\n", 2);
			}
	free_split(&av);
	return (ret);
}
