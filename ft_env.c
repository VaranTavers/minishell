/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:00:36 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/04/18 17:13:27 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		ft_env(t_list *env, char **av)
{
	t_list	*p;
	t_pair	*pair;

	p = env;
	while (p != NULL)
	{
		pair = (t_pair*)p->content;
		ft_printf("%s=%s\n", pair->key, pair->value);
		p = p->next;
	}
	return (0);
	av = 0;
}
