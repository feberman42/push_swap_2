/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:54:18 by feberman          #+#    #+#             */
/*   Updated: 2023/05/05 17:59:31 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ps;

	c = (unsigned char)c;
	ps = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (ps[i] == c)
			return ((void *) s + i);
		i++;
	}
	return (0);
}
