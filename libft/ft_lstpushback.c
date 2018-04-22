/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 13:54:40 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/12/16 16:55:03 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **begin_list, t_list *elem)
{
	t_list *ptr;

	if (*begin_list == NULL)
	{
		*begin_list = elem;
	}
	else
	{
		ptr = *begin_list;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = elem;
	}
}
