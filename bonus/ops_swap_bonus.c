/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:40:33 by feberman          #+#    #+#             */
/*   Updated: 2023/09/13 11:03:08 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ops_sa(t_stacks *stacks)
{
	ops_ra(stacks, 0);
	ops_pb(stacks, 0);
	ops_rra(stacks, 0);
	ops_pa(stacks, 0);
}

void	ops_sb(t_stacks *stacks)
{
	ops_rb(stacks, 0);
	ops_pa(stacks, 0);
	ops_rrb(stacks, 0);
	ops_pb(stacks, 0);
}
