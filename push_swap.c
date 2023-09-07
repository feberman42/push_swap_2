/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:36:32 by feberman          #+#    #+#             */
/*   Updated: 2023/09/07 10:04:00 by feberman         ###   ########.fr       */
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
	int	section_size;
	int	sort_n;
	int	section_border;
	int	value_index;
	int	pushed;

	sort_n = (stacks->back - stacks->front) + 1;
	section_size = (sort_n / 32) + 1;
	while (stacks->front <= stacks->back)
	{
		section_border = stacks->back - section_size;
		if (section_border < stacks->front)
			section_border = stacks->front;
		pushed = 0;
		while (pushed < (stacks->back - section_border + 1))
		{
			value_index = get_index(stacks->arr, (*(stacks->a))->value);
			if (value_index <= stacks->back && value_index >= section_border)
			{
				ops_pb(stacks);
				pushed++;
			}
			else
				ops_ra(stacks);
		}
		stacks->back = section_border - 1;
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
