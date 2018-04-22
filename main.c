/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 11:52:02 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/04/20 17:38:57 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int			prepare(char *command, t_list *env)
{
	char	*trim;
	int		ret;
	char	**split;
	int		i;

	trim = ft_strtrim(command);
	split = ft_smartsplit(trim, ';');
	ft_strdel(&trim);
	i = 0;
	ret = 0;
	while (split[i] != 0)
	{
		trim = ft_strtrim(split[i]);
		ret = ft_interpret(&trim, env);
		i++;
	}
	free_split(&split);
	return (ret);
}

int			ft_interpret_file(char *file, t_list *env)
{
	int		fd;
	int		num;
	char	*command;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	while ((num = get_next_line(fd, &command)))
	{
		if (prepare(command, env) == -1)
			break ;
		ft_strdel(&command);
	}
	close(fd);
	return (1);
}

void		do_files(int ac, char **av, t_list *env)
{
	int		num;

	num = 1;
	while (num < ac)
	{
		if (!ft_interpret_file(av[num], env))
		{
			ft_putstr_fd(av[num], 2);
			ft_putstr_fd(": can't access file\n", 2);
		}
		num++;
	}
}

int			main(int ac, char **av)
{
	char		*command;
	int			num;
	t_list		*env;

	env = init_environ();
	if (ac == 1)
	{
		ft_printf("minishell $> ");
		while ((num = get_next_line(0, &command)))
		{
			if (ft_strlen(command) > 0)
				if (prepare(command, env) == -1)
					break ;
			ft_strdel(&command);
			ft_printf("minishell $> ");
		}
	}
	else
		do_files(ac, av, env);
	ft_lstdel(&env, &free_pair);
	return (0);
}
