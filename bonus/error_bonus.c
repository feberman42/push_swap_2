/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:15:52 by feberman          #+#    #+#             */
/*   Updated: 2023/09/13 13:34:26 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error(t_stacks *stacks)
{
	ft_putendl_fd("Error\n", 1);
	free_bonus(stacks);
	exit(1);
}

void	free_bonus(t_stacks *stacks)
{
	free_list(stacks->a);
	free_list(stacks->b);
	free(stacks->arr);
	free(stacks);
}