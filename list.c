/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:53:51 by feberman          #+#    #+#             */
/*   Updated: 2023/08/25 18:06:22 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->value = value;
	node->next = node;
	node->prev = node;
	return (node);
}

void	list_add(t_node **list, t_node *node)
{
	if ((*list))
	{
		node->next = *list;
		node->prev = (*list)->prev;
		(*list)->prev->next = node;
		(*list)->prev = node;
	}
	else
	{
		node->next = node;
		node->prev = node;
	}
	*list = node;
}

void	list_print(t_node **list)
{
	t_node	*trv;

	trv = *list;
	if (!trv)
		return ;
	while (1)
	{
		ft_printf("%i\n", trv->value);
		trv = trv->next;
		if (trv == *list)
			break ;
	}
}
