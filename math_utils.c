/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:52:56 by feberman          #+#    #+#             */
/*   Updated: 2023/09/12 13:44:51 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_pow(int base, int exp)
{
	int	res;

	res = 1;
	while (exp-- > 0)
		res *= base;
	return (res);
}

long int	*convert_to_bi(long int *bin, int nb)
{
	int	div;
	int	i;

	i = 0;
	while (i < BEAM_SIZE)
		bin[i++] = 0;
	div = my_pow(2, BEAM_SIZE - 1);
	i = 0;
	while (i < BEAM_SIZE)
	{
		bin[i++] = nb / div;
		nb %= div;
		div /= 2;
	}
	return (bin);
}

int	ft_abs(int value)
{
	if (value < 0)
		value *= -1;
	return (value);
}
