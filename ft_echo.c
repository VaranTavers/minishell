/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:04:31 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/04/18 17:13:15 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		ft_echo(t_list *env, char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i] != 0)
	{
		j = 0;
		ft_printf("%s", av[i]);
		if (av[i + 1] != 0)
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	return (0);
	env = 0;
}
