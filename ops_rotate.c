/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:44:50 by feberman          #+#    #+#             */
/*   Updated: 2023/09/13 10:17:41 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ops_ra(t_stacks *stacks, int mode)
{
	*(stacks->a) = (*(stacks->a))->next;
	if (mode)
		return (append_ops(stacks, RA));
	return (1);
}

int	ops_rb(t_stacks *stacks, int mode)
{
	*(stacks->b) = (*(stacks->b))->next;
	if (mode)
		return (append_ops(stacks, RB));
	return (1);
}

int	ops_rra(t_stacks *stacks, int mode)
{
	*(stacks->a) = (*(stacks->a))->prev;
	if (mode)
		return (append_ops(stacks, RRA));
	return (1);
}

int	ops_rrb(t_stacks *stacks, int mode)
{
	*(stacks->b) = (*(stacks->b))->prev;
	if (mode)
		return (append_ops(stacks, RRB));
	return (1);
}

int	rotate_to(t_stacks *stacks, t_stack stack, int value)
{
	int	moves;

	if (stack == A)
		moves = search_in_stack(stacks->a, value);
	else
		moves = search_in_stack(stacks->b, value);
	move(stacks, stack, moves);
	return (1);
}
