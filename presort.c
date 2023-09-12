/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:37:44 by feberman          #+#    #+#             */
/*   Updated: 2023/09/12 14:34:54 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_section_size(t_stacks *stacks)
{
	stacks->section_size = (((stacks->back - stacks->front) + 1) / \
		((stacks->arr[0] / 40) + 4)) + 1;
	stacks->center = ((stacks->back - stacks->front) / 2) + stacks->front;
	if ((stacks->back - stacks->front) <= 10)
	{
		stacks->section_size = 100;
		stacks->center = stacks->back;
	}
}

int	index_to_push(t_stacks *stacks, int index, int i)
{
	if (index <= stacks->center && index >= stacks->center - \
		(i * stacks->section_size) && index >= stacks->front)
		return (1);
	if (index > stacks->center && index <= stacks->center + \
		(i * stacks->section_size) && index <= stacks->back)
		return (-1);
	return (0);
}

void	look_back(t_stacks *stacks, int *value_index, t_node **check, int i)
{
	if (!index_to_push(stacks, *value_index, i))
	{
		if (index_to_push(stacks, get_index(stacks->arr, \
			(*(stacks->a))->prev->value), i))
		{
			ops_rra(stacks, 1);
			*value_index = get_index(stacks->arr, (*(stacks->a))->value);
			*check = (*(stacks->a))->prev;
		}
	}
}

int	evaluate_index(int index, t_stacks *stacks, int i)
{
	if (index_to_push(stacks, index, i) > 0)
	{
		ops_pb(stacks, 1);
		return (1);
	}
	else if (index_to_push(stacks, index, i) < 0)
	{
		ops_pb(stacks, 1);
		if ((*(stacks->b))->next != *(stacks->b))
			ops_rb(stacks, 1);
		return (1);
	}
	else
	{
		ops_ra(stacks, 1);
		return (0);
	}
}
