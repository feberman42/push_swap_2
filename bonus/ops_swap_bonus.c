/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:40:33 by feberman          #+#    #+#             */
/*   Updated: 2023/09/13 13:08:01 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ops_sa(t_stacks *stacks)
{
	ops_ra(stacks);
	ops_pb(stacks);
	ops_rra(stacks);
	ops_pa(stacks);
}

void	ops_sb(t_stacks *stacks)
{
	ops_rb(stacks);
	ops_pa(stacks);
	ops_rrb(stacks);
	ops_pb(stacks);
}

void	ops_ss(t_stacks *stacks)
{
	ops_sa(stacks);
	ops_sb(stacks);
}
