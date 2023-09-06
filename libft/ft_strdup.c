/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:21:41 by feberman          #+#    #+#             */
/*   Updated: 2023/05/07 18:06:26 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dup;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (dup == 0)
		return (dup);
	ft_strlcpy(dup, s, len + 1);
	return (dup);
}
