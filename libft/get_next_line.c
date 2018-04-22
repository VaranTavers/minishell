/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 12:28:14 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/01/24 14:15:38 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file	*get_old_buf(t_list **fd_list, int fd)
{
	t_list	*i;
	t_file	*ret;

	i = *fd_list;
	while (i && ((t_file*)(i->content))->fd != fd)
		i = i->next;
	if (i)
		return ((t_file*)(i->content));
	if (!(ret = (t_file*)malloc(sizeof(*ret))) ||
			!(ret->buf = ft_strnew(0)))
		return (NULL);
	ret->fd = fd;
	if (!(i = (t_list*)malloc(sizeof(*i))))
	{
		free(ret->buf);
		free(ret);
		return (NULL);
	}
	i->next = *fd_list;
	i->content = ret;
	i->content_size = sizeof(ret);
	*fd_list = i;
	return (ret);
}

char	*ft_strcmov(t_file *current)
{
	char	*ret;
	int		i;
	char	*tmp;

	i = 0;
	while ((current->buf)[i] != 0 && (current->buf)[i] != '\n')
		i++;
	ret = ft_strnew(i);
	ft_memcpy(ret, current->buf, i + 1);
	ret[i] = 0;
	tmp = current->buf;
	if ((current->buf)[i] != 0)
		current->buf = ft_strdup(current->buf + i + 1);
	else
		current->buf = ft_strnew(0);
	free(tmp);
	return (ret);
}

int		not_finished(t_file *current)
{
	char	*tmp;
	char	buf[BUFF_SIZE + 1];
	int		ret;

	while ((ret = read(current->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		tmp = ft_strjoin(current->buf, buf);
		free(current->buf);
		current->buf = tmp;
		if (ft_strchr(tmp, '\n'))
			return (1);
	}
	if (ret == 0 && ft_strlen(current->buf) > 0)
		return (1);
	return (ret);
}

void	ft_fclose(t_list **fd_list, int fd)
{
	t_list	*i;
	t_file	*tmp;
	t_list	*elozo;

	i = *fd_list;
	elozo = NULL;
	while (i && ((t_file*)((*fd_list)->content))->fd != fd)
	{
		elozo = i;
		i = i->next;
	}
	if (i)
	{
		tmp = (t_file*)i->content;
		free(tmp->buf);
		free(tmp);
		if (!elozo)
			*fd_list = (*fd_list)->next;
		else
			elozo->next = i->next;
		free(i);
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*fd_list;
	t_file			*current;
	int				ret;

	if (fd < 0 || line == NULL || read(fd, 0, 0) < 0
			|| !(current = get_old_buf(&fd_list, fd)))
		return (-1);
	if (ft_strchr(current->buf, '\n'))
	{
		*line = ft_strcmov(current);
		return (1);
	}
	ret = not_finished(current);
	if (ret == 1)
		*line = ft_strcmov(current);
	else
		ft_fclose(&fd_list, fd);
	return (ret);
}
