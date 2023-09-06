/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:36:32 by feberman          #+#    #+#             */
/*   Updated: 2023/09/06 10:37:12 by feberman         ###   ########.fr       */
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
	if (!sort(stacks))
		error_int();
	free(arr);
	free_stacks(stacks);
	return (0);
}

int	sort(t_stacks *stacks)
{
	long int		*next;

	stacks->front = last_sorted_front(stacks) + 1;
	stacks->back = last_sorted_back(stacks) - 1;
	if (stacks->front >= stacks->arr[0] - stacks->back + 1)
		stacks->back = stacks->arr[0];
	else
		stacks->front = 1;
	while (stacks->front <= stacks->back)
	{
		// ft_printf("start beam loop\ni = %i\te = %i\n", stacks->front, stacks->back);
		next = search_beam(stacks, A);
		if (!next)
			return (0);
		// print_beam(next);
		process_beam(next, stacks, A);
		free(next);
	}
	rotate_to(stacks, A, find_insetion_point(stacks));
	final_push(stacks);
	rotate_to(stacks, A, stacks->arr[1]);
	return (1);
}
