/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:57:12 by feberman          #+#    #+#             */
/*   Updated: 2023/06/15 19:02:28 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free(char *s1, char *s2)
{
	if (s1 != 0)
		free(s1);
	if (s2 != 0)
		free(s2);
	return (0);
}

char	*ft_join(char *s1, char *s2)
{
	char	*out;
	int		len1;
	int		len2;
	int		i;

	if (s1 == 0)
		return (s2);
	else if (s2 == 0)
		ft_free(s1, s2);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	out = malloc(len1 + len2 + 1);
	if (out == 0)
		return (ft_free(s1, s2));
	i = 0;
	while (i++ < len1)
		out[i - 1] = s1[i - 1];
	i = 0;
	while (i++ < len2)
		out[i - 1 + len1] = s2[i - 1];
	out[len1 + len2] = '\0';
	ft_free(s1, s2);
	return (out);
}

int	ft_line_complete(char *line)
{
	int	i;

	if (line == 0)
		return (0);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n' || line[i] == -1)
		{
			if (line[i] == -1)
				line[i] = '\0';
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	sub = malloc(len + 1);
	if (sub == 0)
		return (sub);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
