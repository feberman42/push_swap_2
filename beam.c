/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beam.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:12:45 by feberman          #+#    #+#             */
/*   Updated: 2023/09/06 10:36:46 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	*search_beam(t_stacks *stacks, t_stack stack)
{
	long int		*beam;
	int				i;
	unsigned int	cost;
	int				best;

	beam = malloc(sizeof(long int) * BEAM_SIZE);
	if (!beam)
		return (0);
	cost = 0 - 1;
	i = 0;
	while (i < my_pow(2, BEAM_SIZE))
	{
		beam = get_beam(beam, i, stacks->front, stacks->back);
		if (beam_cost(beam, stacks, stack) < cost)
		{
			cost = beam_cost(beam, stacks, stack);
			if (cost < 0)
				return (0);
			best = i;
		}
		i++;
	}
	return (get_beam(beam, best, stacks->front, stacks->back));
}

long int	*get_beam(long int *beam, int i, int front, int back)
{
	beam = convert_to_bi(beam, i);
	beam = ref_to_beam(beam, back, front);
	return (beam);
}

long int	*ref_to_beam(long int *beam, int back, int front)
{
	int	i;

	i = 0;
	while (i < BEAM_SIZE)
	{
		if (beam[i] == 0)
			beam[i] = front++;
		else
			beam[i] = back--;
		if (front > back)
		{
			i++;
			while (i < BEAM_SIZE)
				beam[i++] = BEAM_STOP;
			return (beam);
		}
		i++;
	}
	return (beam);
}

unsigned int	beam_cost(long int *beam, t_stacks *stacks, t_stack stack)
{
	unsigned int	cost;
	int				i;
	t_node			*start;
	t_node			*find;
	long int		*ignore;

	cost = 0;
	if (stack == A)
		start = *(stacks->a);
	else
		start = *(stacks->b);
	find = start;
	ignore = create_ignore();
	if (!ignore)
		return (-1);
	i = 0;
	while (i < BEAM_SIZE)
	{
		if (beam[i] == BEAM_STOP)
			break ;
		while (find->value != stacks->arr[beam[i]])
			find = find->next;
		cost += move_cost(start, find, ignore);
		start = find;
		ignore[i] = find->value;
		i++;
	}
	free(ignore);
	return (cost);
}

void	process_beam(long int *beam, t_stacks *stacks, t_stack stack)
{
	int	i;

	i = 0;
	while (i < 1)
	{
		if (beam[i] == BEAM_STOP)
			return ;
		rotate_to(stacks, stack, stacks->arr[beam[i]]);
		ops_pb(stacks);
		if (beam[i] == stacks->front)
			stacks->front++;
		else
		{
			stacks->back--;
			ops_rb(stacks);
		}
		i++;
	}
}

void	print_beam(long int *beam)
{
	int	i;

	i = 0;
	while (i < BEAM_SIZE)
	{
		ft_putnbr_fd(beam[i], 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putendl_fd("", 1);
}

int	in_beam(long int nb, long int *beam)
{
	int	i;

	i = 0;
	while (i < BEAM_SIZE)
	{
		if (nb == beam[i])
			return (1);
		i++;
	}
	return (0);
}

long int	*create_ignore(void)
{
	long int	*ignore;
	int			i;

	ignore = malloc(sizeof(int) * BEAM_SIZE);
	if (!ignore)
		return (0);
	i = 0;
	while (i < BEAM_SIZE)
		ignore[i++] = BEAM_STOP;
	return (ignore);
}