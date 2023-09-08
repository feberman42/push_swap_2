/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_precheck.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:32:08 by feberman          #+#    #+#             */
/*   Updated: 2023/09/08 13:00:26 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	last_sorted_front(t_stacks *stacks)
{
	t_node	*trv;
	int		index;

	index = 1;
	trv = *(stacks->a);
	while (trv->value != stacks->arr[index])
		trv = trv->next;
	while (1)
	{
		if (trv->value == stacks->arr[index])
			index++;
		trv = trv->next;
		if (trv->value == stacks->arr[1])
			break ;
	}
	return (index - 1);
}

int	last_sorted_back(t_stacks *stacks)
{
	t_node	*trv;
	int		index;

	index = stacks->arr[0];
	trv = *(stacks->a);
	while (trv->value != stacks->arr[index])
		trv = trv->prev;
	while (1)
	{
		if (trv->value == stacks->arr[index])
			index--;
		trv = trv->prev;
		if (trv->value == stacks->arr[stacks->arr[0]])
			break ;
	}
	return (index + 1);
}

void	sorted_precheck(t_stacks *stacks)
{
	stacks->front = last_sorted_front(stacks) + 1;
	stacks->back = last_sorted_back(stacks) - 1;
	if (stacks->front >= stacks->arr[0] - stacks->back + 1)
		stacks->back = stacks->arr[0];
	else
		stacks->front = 1;
	set_section_size(stacks);
}