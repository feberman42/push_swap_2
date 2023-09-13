/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:36:32 by feberman          #+#    #+#             */
/*   Updated: 2023/09/13 13:55:27 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	int			*arr;
	t_stacks	*stacks;
	char		*ops;

	arr = create_array(argc, argv);
	if (!arr)
		return (1);
	stacks = create_stacks(arr);
	sort_arr(arr);
	
	while(1)
	{
		ops = get_next_line(0);
		if (!ops)
			break ;
		do_operation(ops, stacks);
	}
	//evaluate
	ft_putendl_fd("DONE\n", 1);
	return (0);
}

void	do_operation(char *ops, t_stacks *stacks)
{
	if (!ft_strncmp(ops, "ra\n", 3))
		ops_ra(stacks);
	else if (!ft_strncmp(ops, "rb\n", 3))
		ops_rb(stacks);
	else if (!ft_strncmp(ops, "rra\n", 4))
		ops_rra(stacks);
	else if (!ft_strncmp(ops, "rrb\n", 4))
		ops_rrb(stacks);
	else if (!ft_strncmp(ops, "rr\n", 3))
		ops_rr(stacks);
	else if (!ft_strncmp(ops, "rrr\n", 4))
		ops_rrr(stacks);
	else if (!ft_strncmp(ops, "pa\n", 3))
		ops_pa(stacks);
	else if (!ft_strncmp(ops, "pb\n", 3))
		ops_pb(stacks);
	else if (!ft_strncmp(ops, "sa\n", 3))
		ops_sa(stacks);
	else if (!ft_strncmp(ops, "sb\n", 3))
		ops_sb(stacks);
	else if (!ft_strncmp(ops, "ss\n", 3))
		ops_ss(stacks);
	else
		error(stacks);
}

// int	check(t_stacks *stacks)
// {
// 	t_node	*trv;

// 	if (*(stacks->b))
// 		return (0);
		
// }