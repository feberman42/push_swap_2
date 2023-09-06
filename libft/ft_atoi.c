/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:19:15 by feberman          #+#    #+#             */
/*   Updated: 2023/05/07 13:37:36 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int			i;
	long int	out;
	int			neg;

	neg = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	out = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		out *= 10;
		out += nptr[i] - '0';
		i++;
	}
	return ((int)(out * neg));
}
