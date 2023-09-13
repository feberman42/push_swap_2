/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:56:22 by feberman          #+#    #+#             */
/*   Updated: 2023/09/13 10:18:54 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	filter(t_stacks *stacks)
{
	filter_useless_rotate(stacks);
	filter_useless_reverse_rotate(stacks);
	filter_double_rotate(stacks);
	filter_double_reverse_rotate(stacks);
}

void	filter_useless_rotate(t_stacks *stacks)
{
	t_node	*trv;
	t_node	*check;

	trv = stacks->operations;
	while (trv)
	{
		if (trv->value == RA || trv->value == RB)
		{
			check = trv->next;
			while (check)
			{
				if (check->value == trv->value + 2)
				{
					remove_ops(stacks, check);
					remove_ops(stacks, trv);
					filter_useless_rotate(stacks);
					return ;
				}
				else if (check->value == PA || check->value == PB)
					break ;
				check = check->next;
			}
		}
		trv = trv->next;
	}
}

void	filter_useless_reverse_rotate(t_stacks *stacks)
{
	t_node	*trv;
	t_node	*check;

	trv = stacks->operations;
	while (trv)
	{
		if (trv->value == RRA || trv->value == RRB)
		{
			check = trv->next;
			while (check)
			{
				if (check->value == trv->value - 2)
				{
					remove_ops(stacks, check);
					remove_ops(stacks, trv);
					filter_useless_rotate(stacks);
					return ;
				}
				else if (check->value == PA || check->value == PB)
					break ;
				check = check->next;
			}
		}
		trv = trv->next;
	}
}

void	filter_double_rotate(t_stacks *stacks)
{
	t_node	*trv;
	t_node	*check;

	trv = stacks->operations;
	while (trv)
	{
		if (trv->value == RA || trv->value == RB)
		{
			check = trv->next;
			while (check)
			{
				if ((check->value == RA || check->value == RB)
					&& (check->value != trv->value))
				{
					trv->value = RR;
					remove_ops(stacks, check);
					break ;
				}
				else if (check->value == PA || check->value == PB)
					break ;
				check = check->next;
			}
		}
		trv = trv->next;
	}
}

void	filter_double_reverse_rotate(t_stacks *stacks)
{
	t_node	*trv;
	t_node	*check;

	trv = stacks->operations;
	while (trv)
	{
		if (trv->value == RRA || trv->value == RRB)
		{
			check = trv->next;
			while (check)
			{
				if ((check->value == RRA || check->value == RRB)
					&& (check->value != trv->value))
				{
					trv->value = RRR;
					remove_ops(stacks, check);
					break ;
				}
				else if (check->value == PA || check->value == PB)
					break ;
				check = check->next;
			}
		}
		trv = trv->next;
	}
}
