/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:00:36 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/04/18 17:13:38 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		ft_setenv(t_list *env, char **av)
{
	t_pair	*toadd;

	if (av[1] && av[2] && !av[3])
	{
		if (!set_env(env, av[1], av[2]))
		{
			toadd = new_pair(av[1], av[2]);
			ft_lstpushback(&env, ft_lstelem(toadd, sizeof(t_pair*)));
		}
	}
	else
		ft_printf("usage: %s var_name value\n", av[0]);
	return (0);
	env = 0;
}
