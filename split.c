/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:55:51 by feberman          #+#    #+#             */
/*   Updated: 2023/08/11 16:11:46 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ps_split(const char *s)
{
	char	**split;
	int		word_count;

	word_count = count_words(s);
	split = ft_calloc(word_count + 1, sizeof(char *));
	if (!split)
		return (0);
	split[word_count] = 0;
	if (!split_string(split, s, word_count))
		return (free_split(split, word_count));
	return (split);
}

int	split_string(char **split, const char *s, int wc)
{
	int	i;
	int	word;
	int	len;

	i = 0;
	word = 0;
	while (word < wc)
	{
		while (s[i] == ' ')
			i++;
		len = wordlen(s + i);
		split[word] = malloc(len + 1);
		if (!split[word])
			return (0);
		ft_strlcpy(split[word], s + i, len + 1);
		i += len;
		word++;
	}
	return (1);
}

int	wordlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != ' ')
		i++;
	return (i);
}

int	count_words(const char *s)
{
	int	word_count;
	int	i;

	word_count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			i++;
		else
		{
			word_count++;
			while (s[i] != ' ' && s[i])
				i++;
		}
	}
	return (word_count);
}
