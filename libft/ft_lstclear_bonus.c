/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:48:45 by feberman          #+#    #+#             */
/*   Updated: 2023/05/08 14:28:16 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if ((*lst)->next == 0)
		ft_lstdelone(*lst, del);
	else
	{
		ft_lstclear(&((*lst)->next), del);
		ft_lstdelone(*lst, del);
	}
	*lst = 0;
	lst = 0;
}
