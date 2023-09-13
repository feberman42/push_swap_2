/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:52:56 by feberman          #+#    #+#             */
/*   Updated: 2023/09/13 13:24:06 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int value)
{
	if (value < 0)
		value *= -1;
	return (value);
}

int	get_cost(t_stacks *stacks)
{
	if (stacks->back - 1 >= stacks->front + 5)
	{
		return (ft_abs(search_in_stack(\
			stacks->b, stacks->arr[stacks->back - 1])));
	}
	else
		return (INT_MAX);
}
