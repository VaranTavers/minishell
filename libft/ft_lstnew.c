/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:30:50 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/12/16 16:16:43 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ret;

	ret = (t_list*)malloc(sizeof(*ret));
	if (ret != NULL)
	{
		if (content != NULL && content_size != 0)
		{
			ret->content = ft_memalloc(content_size);
			ft_memcpy(ret->content, content, content_size);
			ret->content_size = content_size;
		}
		else
		{
			ret->content = NULL;
			ret->content_size = 0;
		}
		ret->next = NULL;
	}
	return (ret);
}
