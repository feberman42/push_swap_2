/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:26:44 by feberman          #+#    #+#             */
/*   Updated: 2023/09/13 10:19:00 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	append_ops(t_stacks *stacks, t_ops ops)
{
	t_node	*new;
	t_node	*trv;

	new = create_node(ops);
	if (!new)
		return (0);
	new->next = 0;
	new->prev = 0;
	trv = stacks->operations;
	if (!trv)
		stacks->operations = new;
	else
	{
		while (trv->next != 0)
			trv = trv->next;
		trv->next = new;
		new->prev = trv;
	}
	return (1);
}

void	remove_ops(t_stacks *stacks, t_node *ops)
{
	if (!ops)
		return ;
	if (!ops->prev)
		stacks->operations = ops->next;
	else
	{
		ops->prev->next = ops->next;
		if (ops->next)
			ops->next->prev = ops->prev;
	}
	free(ops);
}

void	print_ops(t_stacks *stacks)
{
	t_node	*trv;

	trv = stacks->operations;
	while (trv)
	{
		put_ops_out(trv->value);
		trv = trv->next;
	}
}

void	put_ops_out(t_ops ops)
{
	if (ops == RA)
		ft_putendl_fd("ra", 1);
	else if (ops == RB)
		ft_putendl_fd("rb", 1);
	else if (ops == RRA)
		ft_putendl_fd("rra", 1);
	else if (ops == RRB)
		ft_putendl_fd("rrb", 1);
	else if (ops == RR)
		ft_putendl_fd("rr", 1);
	else if (ops == RRR)
		ft_putendl_fd("rrr", 1);
	else if (ops == PA)
		ft_putendl_fd("pa", 1);
	else if (ops == PB)
		ft_putendl_fd("pb", 1);
	else if (ops == SA)
		ft_putendl_fd("sa", 1);
}
