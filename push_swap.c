/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:36:32 by feberman          #+#    #+#             */
/*   Updated: 2023/09/11 12:53:39 by feberman         ###   ########.fr       */
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
	// ft_printf("start sorting\n");
	precheck(stacks);
	// ft_printf("front: %i\tback: %i\n", stacks->front, stacks->back);
	if (stacks->back >= stacks->front)
		presort(stacks);
	// ft_printf("presort done\n");
	sort(stacks);
	// ft_printf("sorting done\n");
	filter_useless_rotate(stacks);
	filter_useless_reverse_rotate(stacks);
	filter_double_rotate(stacks);
	filter_double_reverse_rotate(stacks);
	// ft_printf("test\n");
	print_ops(stacks);
	// free(arr);
	// free_stacks(stacks);
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
	while (stacks->center + ((i - 1) * stacks->section_size) <= stacks->back || stacks->center - ((i - 1) * stacks->section_size) >= stacks->front)
	{
		check = (*(stacks->a))->prev;
		while (1)
		{
			value_index = get_index(stacks->arr, (*(stacks->a))->value);
			if (!index_to_push(stacks, value_index, i))
			{
				if (index_to_push(stacks, get_index(stacks->arr, (*(stacks->a))->prev->value), i))
				{
					ops_rra(stacks, 1);
					value_index = get_index(stacks->arr, (*(stacks->a))->value);
					check = (*(stacks->a))->prev;
				}
			}
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
	
	// ft_printf("rotate to insertion point\n");
	if (stacks->back >= stacks->front)
		rotate_to(stacks, A, find_insertion_point(stacks));
	// ft_printf("pushing\n");
	while (*(stacks->b))
	{
		pushed = 0;
		if (stacks->back - 1 >= stacks->front + 5)
			cost = ft_abs(search_in_stack(stacks->b, stacks->arr[stacks->back - 1]));
		else
			cost = INT_MAX;
		if (cost < ft_abs(search_in_stack(stacks->b, stacks->arr[stacks->back])))
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
	// ft_printf("rearrange\n");
	rotate_to(stacks, A, stacks->arr[1]);
	return (1);
}
