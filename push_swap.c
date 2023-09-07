/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:36:32 by feberman          #+#    #+#             */
/*   Updated: 2023/09/07 14:53:28 by feberman         ###   ########.fr       */
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
	sorted_precheck(stacks);
	presort(stacks);
	sort(stacks);
	// 	error_int();
	// free(arr);
	// free_stacks(stacks);
	return (0);
}

int	presort(t_stacks *stacks)
{
	int		value_index;
	int		i;
	t_node	*check;

	i = 1;
	while (stacks->center + ((i - 1) * stacks->section_size) <= stacks->back || stacks->center - ((i - 1) * stacks->section_size) >= stacks->front)
	{
		check = (*(stacks->a))->prev;
		while (1)
		{
			value_index = get_index(stacks->arr, (*(stacks->a))->value);
			evaluate_index(value_index, stacks, i);
			if (value_index == get_index(stacks->arr, check->value))
				break ;
		}
		i++;
	}
	return (0);
}

int	sort(t_stacks *stacks)
{	
	// ft_printf("rotate to insertion point");
	rotate_to(stacks, A, find_insertion_point(stacks));
	// ft_printf("push");
	while (*(stacks->b))
	{
		rotate_to(stacks, B, stacks->arr[stacks->back]);
		ops_pa(stacks);
		stacks->back--;
	}
	// ft_printf("rearrange");
	rotate_to(stacks, A, stacks->arr[1]);
	return (1);
}
