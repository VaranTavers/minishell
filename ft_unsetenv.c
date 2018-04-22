/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:00:36 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/04/18 17:13:49 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_delenv(t_list *p, t_list *last)
{
	t_list	*tmp;

	if (p != NULL)
	{
		if (last == NULL)
		{
			free_pair(p->content, 0);
			p->content = p->next->content;
			tmp = p->next;
			p->next = p->next->next;
			free(tmp);
		}
		else
		{
			last->next = p->next;
			free_pair(p->content, 0);
			free(p);
		}
	}
}

int		ft_unsetenv(t_list *env, char **av)
{
	t_list	*p;
	t_pair	*pair;
	t_list	*last;

	if (env && env->next)
	{
		p = env;
		last = NULL;
		pair = (t_pair*)(p->content);
		while (p != NULL && !ft_strequ(av[1], pair->key))
		{
			last = p;
			p = p->next;
			if (p != NULL)
				pair = (t_pair*)(p->content);
		}
		ft_delenv(p, last);
	}
	else
	{
		ft_putstr_fd(av[0], 2);
		ft_putstr_fd(": can't unset last enviromental variable!\n", 2);
	}
	return (0);
}
