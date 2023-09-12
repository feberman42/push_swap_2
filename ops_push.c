/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:04:34 by feberman          #+#    #+#             */
/*   Updated: 2023/09/12 10:00:01 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ops_pa(t_stacks *stacks, int mode)
{
	t_node	*trv;

	trv = *(stacks->b);
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
	if (mode)
		return (append_ops(stacks, PA));
	return (1);
}

int	ops_pb(t_stacks *stacks, int mode)
{
	t_node	*trv;

	trv = *(stacks->a);
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
	if (mode)
		return (append_ops(stacks, PB));
	return (1);
}

void	final_push(t_stacks *stacks)
{
	if (*(stacks->b) == 0)
		return ;
	while ((*(stacks->b))->value < (*(stacks->b))->prev->value)
		ops_rrb(stacks, 1);
	while (*(stacks->b))
		ops_pa(stacks, 1);
}
