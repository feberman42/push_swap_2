/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:09:01 by feberman          #+#    #+#             */
/*   Updated: 2023/09/13 13:10:09 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ops_rr(t_stacks *stacks)
{
	ops_ra(stacks);
	ops_rb(stacks);
}

void	ops_rrr(t_stacks *stacks)
{
	ops_rra(stacks);
	ops_rrb(stacks);
}
