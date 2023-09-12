/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:11:54 by feberman          #+#    #+#             */
/*   Updated: 2023/09/12 13:14:36 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_split(char **split, int size)
{
	int	i;

	if (!split)
		return (0);
	i = 0;
	if (size)
	{
		while (i < size)
		{
			if (split[i])
				free(split[i]);
			i++;
		}
	}
	else
		while (split[i])
			free(split[i++]);
	free(split);
	return (0);
}

int	free_stacks(t_stacks *stacks)
{
	free_list(stacks->a);
	free_list(stacks->b);
	free_ops(stacks->operations);
	free(stacks->arr);
	free(stacks);
	return (0);
}

void	free_ops(t_node *node)
{
	t_node	*tmp;

	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
}

void	free_list(t_node **node)
{
	t_node	*tmp;

	if (!node)
		return ;
	if (*node)
	{
		if ((*node)->prev)
			(*node)->prev->next = 0;
		while (*node)
		{
			tmp = *node;
			*node = (*node)->next;
			free(tmp);
		}
	}
	free(node);
}
