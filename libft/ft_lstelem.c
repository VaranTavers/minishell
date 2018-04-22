/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstelem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:30:50 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/04/15 17:54:25 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstelem(void *content, size_t content_size)
{
	t_list	*ret;

	ret = (t_list*)malloc(sizeof(*ret));
	if (ret != NULL)
	{
		ret->content = content;
		ret->content_size = content_size;
		ret->next = NULL;
	}
	return (ret);
}
