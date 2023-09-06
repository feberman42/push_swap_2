/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:58:48 by feberman          #+#    #+#             */
/*   Updated: 2023/05/10 14:20:13 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	s;
	void	*out;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	s = nmemb * size;
	if (s / size != nmemb)
		return (0);
	out = malloc(s);
	if (out == 0)
		return (0);
	ft_bzero(out, s);
	return (out);
}
