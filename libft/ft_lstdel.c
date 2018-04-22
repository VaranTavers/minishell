/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:38:46 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/11/30 14:01:05 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*p;

	if (alst != NULL)
	{
		p = *alst;
		if (p->next != NULL)
			ft_lstdel(&(p->next), del);
		del(p->content, p->content_size);
		free(p);
		*alst = NULL;
	}
}
