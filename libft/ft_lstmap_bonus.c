/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:34:34 by feberman          #+#    #+#             */
/*   Updated: 2023/05/09 12:29:51 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	t_list	*trv;
	t_list	*node;

	trv = lst;
	out = 0;
	while (trv != 0)
	{
		node = ft_lstnew(f(trv->content));
		if (node == 0)
		{
			ft_lstclear(&out, del);
			return (0);
		}
		ft_lstadd_back(&out, node);
		trv = trv->next;
	}
	return (out);
}
