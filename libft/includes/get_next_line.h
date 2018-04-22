/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 12:18:20 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/04/14 11:59:00 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1023
# include "libft.h"

typedef struct	s_file
{
	int		fd;
	char	*buf;
}				t_file;

int				get_next_line(const int fd, char **line);

#endif
