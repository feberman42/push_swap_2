/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:40:33 by feberman          #+#    #+#             */
/*   Updated: 2023/09/12 13:42:19 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ops_sa(t_stacks *stacks)
{
	ops_ra(stacks, 0);
	ops_pb(stacks, 0);
	ops_rra(stacks, 0);
	ops_pa(stacks, 0);
	return (append_ops(stacks, SA));
}
