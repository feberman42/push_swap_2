/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:36:32 by feberman          #+#    #+#             */
/*   Updated: 2023/09/13 16:34:44 by feberman         ###   ########.fr       */
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
	stacks = create_stacks_bonus(arr);
	sort_arr(arr);
	while(1)
	{
		ops = get_next_line(0);
		if (!ops)
			break ;
		do_operation(ops, stacks);
		free(ops);
	}
	if (check(stacks))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_bonus(stacks);
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
		error(stacks, ops);
}

int	check(t_stacks *stacks)
{
	t_node	*trv;
	int		i;

	if (*(stacks->b))
		return (0);
	trv = *(stacks->a);
	i = 1;
	while (i < stacks->arr[0])
	{
		trv = trv->next;
		i++;
		if (trv->value != stacks->arr[i])
			return (0);
	}
	return (1);
}

t_stacks	*create_stacks_bonus(int *arr)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (0);
	stacks->a = malloc(sizeof(t_node *));
	stacks->b = malloc(sizeof(t_node *));
	if (!stacks->a || !stacks->b)
	{
		free_bonus(stacks);
		return (0);
	}
	*(stacks->a) = 0;
	*(stacks->b) = 0;
	if (!arr_to_stack(stacks, arr))
	{
		free_bonus(stacks);
		return (0);
	}
	stacks->arr = arr;
	return (stacks);
}
