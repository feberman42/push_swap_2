/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:36:32 by feberman          #+#    #+#             */
/*   Updated: 2023/09/07 13:35:36 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int			*arr;
	t_stacks	*stacks;
	int			back;

	arr = create_array(argc, argv);
	if (!arr)
		return (1);
	stacks = create_stacks(arr);
	sort_arr(arr);
	sorted_precheck(stacks);
	back = stacks->back;
	presort(stacks);
	sort(stacks, back);
	// 	error_int();
	// free(arr);
	// free_stacks(stacks);
	return (0);
}

int	presort(t_stacks *stacks)
{
	int		section_size;
	int		center;
	int		value_index;
	int		i;
	t_node	*check;

	section_size = (((stacks->back - stacks->front) + 1) / ((stacks->arr[0] / 40) + 4)) + 1;
	center = ((stacks->back - stacks->front) / 2) + stacks->front;
	i = 1;
	while (center + ((i - 1) * section_size) <= stacks->back || center - ((i - 1) * section_size) >= stacks->front)
	{
		check = 0;
		while (check != *(stacks->a))
		{
			value_index = get_index(stacks->arr, (*(stacks->a))->value);
			if (value_index <= center && value_index >= center - (i * section_size) && value_index >= stacks->front)
				ops_pb(stacks);
			else if (value_index > center && value_index <= center + (i * section_size) && value_index <= stacks->back)
			{
				ops_pb(stacks);
				ops_rb(stacks);
			}
			else
			{
				if (!check)
					check = *(stacks->a);
				ops_ra(stacks);
			}
		}
		i++;
	}
	return (0);
}

int	sort(t_stacks *stacks, int back)
{	
	rotate_to(stacks, A, find_insertion_point(stacks));
	while (*(stacks->b))
	{
		rotate_to(stacks, B, stacks->arr[back]);
		ops_pa(stacks);
		back--;
	}
	rotate_to(stacks, A, stacks->arr[1]);
	return (1);
}
