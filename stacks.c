/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:33:20 by feberman          #+#    #+#             */
/*   Updated: 2023/09/13 13:24:01 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*create_stacks(int *arr)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (0);
	stacks->a = malloc(sizeof(t_node *));
	stacks->b = malloc(sizeof(t_node *));
	if (!stacks->a || !stacks->b)
	{
		free_stacks(stacks);
		return (0);
	}
	*(stacks->a) = 0;
	*(stacks->b) = 0;
	if (!arr_to_stack(stacks, arr))
	{
		free_stacks(stacks);
		return (0);
	}
	stacks->arr = arr;
	stacks->front = 1;
	stacks->back = stacks->arr[0];
	stacks->operations = 0;
	return (stacks);
}

int	search_in_stack(t_node **stack, int value)
{
	t_node	*trv;
	int		r;
	int		rr;

	trv = *stack;
	r = 0;
	while (trv->value != value)
	{
		r++;
		trv = trv->next;
	}
	trv = *stack;
	rr = 0;
	while (trv->value != value)
	{
		rr++;
		trv = trv->prev;
	}
	if (r <= rr)
		return (r);
	else
		return (-1 * rr);
}

int	find_insertion_point(t_stacks *stacks)
{
	int		i;
	t_node	*trv;

	i = 1;
	trv = *(stacks->a);
	while (trv->value != stacks->arr[i])
		i++;
	i++;
	trv = trv->next;
	while (1)
	{
		if (trv->value != stacks->arr[i])
			return (trv->value);
		else if (trv->value == stacks->arr[1])
			return (trv->prev->value);
		trv = trv->next;
		i++;
		if (i > stacks->arr[0])
			i = 1;
	}
	return (trv->value);
}

void	move(t_stacks *stacks, t_stack stack, int moves)
{
	if (moves >= 0)
	{
		while (moves-- > 0)
		{
			if (stack == A)
				ops_ra(stacks, 1);
			else
				ops_rb(stacks, 1);
		}
	}
	else
	{
		while (moves++ < 0)
		{
			if (stack == A)
				ops_rra(stacks, 1);
			else
				ops_rrb(stacks, 1);
		}
	}
}
