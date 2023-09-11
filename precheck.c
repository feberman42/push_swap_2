/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:32:08 by feberman          #+#    #+#             */
/*   Updated: 2023/09/11 12:50:26 by feberman         ###   ########.fr       */
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
	// ft_printf("test\n");
	stacks->front = last_sorted_front(stacks) + 1;
	// ft_printf("front done\n");
	stacks->back = last_sorted_back(stacks) - 1;
	// ft_printf("back done\n");
	if (stacks->front >= stacks->arr[0] - stacks->back + 1)
		stacks->back = stacks->arr[0];
	else
		stacks->front = 1;
}

void	precheck(t_stacks *stacks)
{
	int effect;

	sorted_precheck(stacks);
	effect = stacks->back - stacks->front;
	ops_sa(stacks);
	sorted_precheck(stacks);
	// ft_printf("test\n");
	if (effect <= stacks->back - stacks->front)
	{
		free(stacks->operations);
		ops_sa(stacks);
		free(stacks->operations);
		sorted_precheck(stacks);
		stacks->operations = 0;
	}

	if (stacks->back - stacks->front < 0)
		return ;
	set_section_size(stacks);
}