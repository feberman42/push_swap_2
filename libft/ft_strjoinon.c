/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:17:44 by feberman          #+#    #+#             */
/*   Updated: 2023/07/11 14:38:57 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinon(char const *s1, char const *s2, const char c)
{
	char	*str;
	size_t	i;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(s1_len + s2_len + 2);
	if (str == 0)
		return (str);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	i = 0;
	while (s2[i] != '\0')
	{
		str[i + s1_len + 1] = s2[i];
		i++;
	}
	str[i + s1_len + 1] = '\0';
	return (str);
}
