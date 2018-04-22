/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 11:36:47 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/12/16 16:58:51 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *begin_list, void *content, int cs,
		int (*cmp)(void*, int, void*, int))
{
	t_list *ptr;

	ptr = begin_list;
	while (ptr != NULL)
	{
		if (!cmp(ptr->content, ptr->content_size, content, cs))
			ptr = ptr->next;
		else
			return (ptr);
	}
	return (NULL);
}
