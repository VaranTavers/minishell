/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:52:43 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/12/19 16:33:17 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*p;
	t_list	*fp;

	ret = NULL;
	p = lst;
	while (p != NULL)
	{
		fp = f(p);
		if (fp == NULL)
			return (NULL);
		ft_lstadd(&ret, fp);
		p = p->next;
	}
	return (ret);
}
