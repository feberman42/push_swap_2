/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:01:36 by feberman          #+#    #+#             */
/*   Updated: 2023/08/11 16:14:46 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*error_ptr(void)
{
	ft_putendl_fd("Error", 2);
	return (0);
}

int	error_int(void)
{
	ft_putendl_fd("Error", 2);
	return (0);
}
