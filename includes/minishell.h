/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 13:20:16 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/04/18 16:58:20 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include "../libft/includes/libftprintf.h"
# include "../libft/includes/get_next_line.h"
# include <fcntl.h>

typedef struct	s_pair
{
	char	*key;
	char	*value;
}				t_pair;

int				ft_interpret(char **str, t_list *env);

void			free_split(char ***av);

int				ft_path(t_list *env, char **av, int *ret);

char			*ft_dequotify(const char *src);

char			**ft_smartsplit(char *str, char c);

char			*ft_smartsearch(char *str, char c, int level);

void			ft_dequotify_av(char **av);

t_list			*init_environ(void);

char			*replace_env(t_list *env, const char *input);

char			*get_env(t_list *env, const char *tofind);

int				set_env(t_list *env, const char *tofind, const char *toset);

t_pair			*pair_from_environ(const char *env);

t_pair			*new_pair(const char *key, const char *value);

void			free_pair(void *p, size_t s);

int				ft_cd(t_list *env, char **av);

int				ft_echo(t_list *env, char **av);

int				ft_env(t_list *env, char **av);

int				ft_exit(t_list *env, char **av);

int				ft_setenv(t_list *env, char **av);

int				ft_unsetenv(t_list *env, char **av);
#endif
