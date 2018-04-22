/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 14:11:01 by ztasnadi          #+#    #+#             */
/*   Updated: 2017/12/16 16:45:16 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *begin_list)
{
	int		ret;
	t_list	*ptr;

	ptr = begin_list;
	ret = 0;
	while (ptr != NULL)
	{
		ret++;
		ptr = ptr->next;
	}
	return (ret);
}
