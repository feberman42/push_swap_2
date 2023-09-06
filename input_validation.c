/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:37:38 by feberman          #+#    #+#             */
/*   Updated: 2023/08/11 16:11:37 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_arguments(int argc, char *argv[])
{
	int	i;
	int	n;

	n = 0;
	i = 1;
	while (i < argc)
		n += count_words(argv[i++]);
	return (n);
}
