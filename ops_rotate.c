/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:44:50 by feberman          #+#    #+#             */
/*   Updated: 2023/09/08 10:54:48 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ops_ra(t_stacks *stacks)
{
	*(stacks->a) = (*(stacks->a))->next;
	append_ops(stacks, RA);
}

void	ops_rb(t_stacks *stacks)
{
	*(stacks->b) = (*(stacks->b))->next;
	append_ops(stacks, RB);
}

void	ops_rra(t_stacks *stacks)
{
	*(stacks->a) = (*(stacks->a))->prev;
	append_ops(stacks, RRA);
}

void	ops_rrb(t_stacks *stacks)
{
	*(stacks->b) = (*(stacks->b))->prev;
	append_ops(stacks, RRB);
}

void	rotate_to(t_stacks *stacks, t_stack stack, int value)
{
	int	moves;

	if (stack == A)
		moves = search_in_stack(stacks->a, value);
	else
		moves = search_in_stack(stacks->b, value);
	if (moves >= 0)
		while (moves-- > 0)
		{
			if (stack == A)
				ops_ra(stacks);
			else
				ops_rb(stacks);
		}
	else
		while (moves++ < 0)
		{
			if (stack == A)
				ops_rra(stacks);
			else
				ops_rrb(stacks);
		}
}
