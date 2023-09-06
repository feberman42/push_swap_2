/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:46:46 by feberman          #+#    #+#             */
/*   Updated: 2023/05/05 16:57:18 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = 0;
	while (size > 0 && dst[dst_len] != '\0')
	{
		dst_len++;
		size--;
	}
	if (size == 0)
		return (dst_len + src_len);
	i = 0;
	while (size > 1 && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
		size--;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
