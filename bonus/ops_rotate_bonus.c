/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:44:50 by feberman          #+#    #+#             */
/*   Updated: 2023/09/13 11:03:07 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ops_ra(t_stacks *stacks)
{
	*(stacks->a) = (*(stacks->a))->next;
}

void	ops_rb(t_stacks *stacks)
{
	*(stacks->b) = (*(stacks->b))->next;
}

void	ops_rra(t_stacks *stacks)
{
	*(stacks->a) = (*(stacks->a))->prev;
}

void	ops_rrb(t_stacks *stacks)
{
	*(stacks->b) = (*(stacks->b))->prev;
}
