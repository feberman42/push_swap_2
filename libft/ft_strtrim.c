/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:32:58 by feberman          #+#    #+#             */
/*   Updated: 2023/05/03 15:58:57 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_instr(const char *str, const char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		sub_start;
	int		sub_end;
	int		sublen;
	char	*sub;
	int		i;

	sub_start = 0;
	sub_end = ft_strlen(s1) - 1;
	while (ft_instr(set, s1[sub_start]) == 1)
		sub_start++;
	while (ft_instr(set, s1[sub_end]) == 1 && sub_end >= 0)
		sub_end--;
	if (sub_start > sub_end)
		sublen = 0;
	else
		sublen = sub_end - sub_start + 1;
	sub = malloc(sublen + 1);
	if (sub == 0)
		return (sub);
	sub[sublen] = '\0';
	i = 0;
	while (sub_start <= sub_end)
		sub[i++] = s1[sub_start++];
	return (sub);
}
