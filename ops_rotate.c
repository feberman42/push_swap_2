/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:44:50 by feberman          #+#    #+#             */
/*   Updated: 2023/09/06 12:31:38 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ops_ra(t_stacks *stacks)
{
	*(stacks->a) = (*(stacks->a))->next;
	write(1, "ra\n", 3); 
}

void	ops_rb(t_stacks *stacks)
{
	*(stacks->b) = (*(stacks->b))->next;
	write(1, "rb\n", 3); 
}

void	ops_rra(t_stacks *stacks)
{
	*(stacks->a) = (*(stacks->a))->prev;
	write(1, "rra\n", 4); 
}

void	ops_rrb(t_stacks *stacks)
{
	*(stacks->b) = (*(stacks->b))->prev;
	write(1, "rrb\n", 4); 
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
