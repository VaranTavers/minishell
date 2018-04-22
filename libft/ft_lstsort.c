/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztasnadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:48:20 by ztasnadi          #+#    #+#             */
/*   Updated: 2018/03/03 14:37:50 by ztasnadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	swap_content(t_list *a, t_list *b)
{
	void	*tmp;

	tmp = a->content;
	a->content = b->content;
	b->content = tmp;
}

void		ft_lstsort(t_list *lst, int (*cmp)(void*, void*))
{
	t_list	*maxx;
	t_list	*ptr;
	t_list	*last;

	if (lst != NULL)
	{
		maxx = NULL;
		while (maxx != lst->next)
		{
			ptr = lst;
			last = lst->next;
			while (ptr->next != maxx)
			{
				if (cmp(ptr->content, ptr->next->content) > 0)
				{
					swap_content(ptr, ptr->next);
					last = ptr->next;
				}
				ptr = ptr->next;
			}
			maxx = last;
		}
	}
}
