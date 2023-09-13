/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:36:32 by feberman          #+#    #+#             */
/*   Updated: 2023/09/13 10:21:21 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int			*arr;
	t_stacks	*stacks;

	arr = create_array(argc, argv);
	if (!arr)
		return (1);
	stacks = create_stacks(arr);
	sort_arr(arr);
	if (!precheck(stacks))
	{
		free_stacks(stacks);
		return (error_int());
	}
	if (stacks->back >= stacks->front)
		presort(stacks);
	sort(stacks);
	filter(stacks);
	print_ops(stacks);
	free_stacks(stacks);
	return (0);
}

int	presort(t_stacks *stacks)
{
	int		value_index;
	int		i;
	t_node	*check;
	int		pushed;

	pushed = 0;
	i = 1;
	while (stacks->center + ((i - 1) * stacks->section_size) <= stacks->back 
		|| stacks->center - ((i - 1) * stacks->section_size) >= stacks->front)
	{
		check = (*(stacks->a))->prev;
		while (1)
		{
			value_index = get_index(stacks->arr, (*(stacks->a))->value);
			look_back(stacks, &value_index, &check, i);
			pushed += evaluate_index(value_index, stacks, i);
			if (pushed == stacks->back - stacks->front + 1)
				return (0);
			if (value_index == get_index(stacks->arr, check->value))
				break ;
		}
		i++;
	}
	return (0);
}

int	sort(t_stacks *stacks)
{
	int	cost;
	int	pushed;

	if (stacks->back >= stacks->front)
		rotate_to(stacks, A, find_insertion_point(stacks));
	while (*(stacks->b))
	{
		pushed = 0;
		cost = get_cost(stacks);
		if (cost < ft_abs(search_in_stack(\
			stacks->b, stacks->arr[stacks->back])))
		{
			rotate_to(stacks, B, stacks->arr[stacks->back - 1]);
			ops_pa(stacks, 1);
			ops_ra(stacks, 1);
			pushed++;
		}
		rotate_to(stacks, B, stacks->arr[stacks->back]);
		ops_pa(stacks, 1);
		if (pushed)
			ops_rra(stacks, 1);
		stacks->back -= pushed + 1;
	}
	rotate_to(stacks, A, stacks->arr[1]);
	return (1);
}
