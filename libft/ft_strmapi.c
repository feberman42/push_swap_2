/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:50:56 by feberman          #+#    #+#             */
/*   Updated: 2023/05/11 12:08:58 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		size;
	int		i;
	char	*out;

	size = ft_strlen(s);
	i = 0;
	out = malloc(size + 1);
	if (out == 0)
		return (out);
	out[size] = '\0';
	while (i < size)
	{
		out[i] = f(i, s[i]);
		i++;
	}
	return (out);
}
