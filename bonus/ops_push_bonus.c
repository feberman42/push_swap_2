/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:04:34 by feberman          #+#    #+#             */
/*   Updated: 2023/09/13 13:47:39 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ops_pa(t_stacks *stacks)
{
	t_node	*trv;

	trv = *(stacks->b);
	if (!trv)
		return ;
	if (trv->next == trv)
		*(stacks->b) = 0;
	else
	{
		trv->next->prev = trv->prev;
		trv->prev->next = trv->next;
		*(stacks->b) = trv->next;
		trv->next = trv;
		trv->prev = trv;
	}
	if (*(stacks->a))
	{
		trv->next = *(stacks->a);
		trv->prev = (*(stacks->a))->prev;
		trv->next->prev = trv;
		trv->prev->next = trv;
	}
	*(stacks->a) = trv;
}

void	ops_pb(t_stacks *stacks)
{
	t_node	*trv;

	trv = *(stacks->a);
	if (!trv)
		return ;
	if (trv->next == trv)
		*(stacks->a) = 0;
	else
	{
		trv->next->prev = trv->prev;
		trv->prev->next = trv->next;
		*(stacks->a) = trv->next;
		trv->next = trv;
		trv->prev = trv;
	}
	if (*(stacks->b))
	{
		trv->next = *(stacks->b);
		trv->prev = (*(stacks->b))->prev;
		trv->next->prev = trv;
		trv->prev->next = trv;
	}
	*(stacks->b) = trv;
}
