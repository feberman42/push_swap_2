/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:37:44 by feberman          #+#    #+#             */
/*   Updated: 2023/09/07 14:54:10 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_section_size(t_stacks *stacks)
{
	int	section_size;
	int	center;

	section_size = (((stacks->back - stacks->front) + 1) / ((stacks->arr[0] / 40) + 4)) + 1;
	center = ((stacks->back - stacks->front) / 2) + stacks->front;
	if ((center - stacks->front) <= 3)
		section_size = 100;
	return (section_size);
}

int	index_to_push(t_stacks *stacks, int index, int i)
{
	if (index <= stacks->center && index >= stacks->center - (i * stacks->section_size) && index >= stacks->front)
		return (1);
	if (index > stacks->center && index <= stacks->center + (i * stacks->section_size) && index <= stacks->back)
		return (-1);
	return (0);
}

void	evaluate_index(int index, t_stacks *stacks, int i)
{
	if (index_to_push(stacks, index, i) > 0)
		ops_pb(stacks);
	else if (index_to_push(stacks, index, i) < 0)
	{
		ops_pb(stacks);
		if ((*(stacks->b))->next != *(stacks->b))
			ops_rb(stacks);
	}
	else
		ops_ra(stacks);
}