/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:12:01 by feberman          #+#    #+#             */
/*   Updated: 2023/05/07 13:38:08 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_size(long int nbr)
{
	int	size;

	size = 0;
	if (nbr < 0)
	{
		size++;
		nbr *= -1;
	}
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

void	ft_itoa_rec(long int ln, char *out)
{
	int	i;

	i = 0;
	while (out[i] != '\0')
		i++;
	if (ln <= 9)
		out[i] = ln + '0';
	else
	{
		ft_itoa_rec(ln / 10, out);
		ft_itoa_rec(ln % 10, out);
	}
}

char	*ft_itoa(int n)
{
	long int	ln;
	char		*out;
	int			size;

	ln = (long int) n;
	size = ft_number_size(ln);
	out = malloc(size + 1);
	if (out == 0)
		return (out);
	ft_bzero(out, size + 1);
	if (ln < 0)
	{
		out[0] = '-';
		ln *= -1;
	}
	ft_itoa_rec(ln, out);
	return (out);
}
