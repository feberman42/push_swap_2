/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:44:50 by feberman          #+#    #+#             */
/*   Updated: 2023/09/13 13:45:49 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ops_ra(t_stacks *stacks)
{
	if (*(stacks->a))
		*(stacks->a) = (*(stacks->a))->next;
}

void	ops_rb(t_stacks *stacks)
{
	if (*(stacks->b))
		*(stacks->b) = (*(stacks->b))->next;
}

void	ops_rra(t_stacks *stacks)
{
	if (*(stacks->a))
		*(stacks->a) = (*(stacks->a))->prev;
}

void	ops_rrb(t_stacks *stacks)
{
	if (*(stacks->b))
		*(stacks->b) = (*(stacks->b))->prev;
}
