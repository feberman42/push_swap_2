/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:37:38 by feberman          #+#    #+#             */
/*   Updated: 2023/09/13 10:22:09 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_arguments(int argc, char *argv[])
{
	int	i;
	int	n;

	n = 0;
	i = 1;
	while (i < argc)
		n += count_words(argv[i++]);
	return (n);
}

int	has_doubles(int *arr)
{
	int	i;
	int	j;

	i = 1;
	while (i <= arr[0])
	{
		j = i + 1;
		while (j <= arr[0])
			if (arr[i] == arr[j++])
				return (1);
		i++;
	}
	return (0);
}

int	check_chars(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (i == 0 && (arg[i] == '-' || arg[i] == '+'))
			i++;
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_overflow(char *arg)
{
	char	*max;
	int		overflow;

	overflow = 0;
	max = 0;
	if (arg[0] == '-')
	{
		max = ft_strdup("2147483648");
		arg++;
	}
	else
	{
		max = ft_strdup("2147483647");
		if (arg[0] == '+')
			arg++;
	}
	if (ft_strlen(arg) > 10)
		overflow = 1;
	else if (ft_strlen(arg) == 10)
		if (ft_strncmp(arg, max, 10) > 0)
			overflow = 1;
	if (max)
		free(max);
	return (overflow);
}

int	check_arg(char *arg)
{
	if (!check_chars(arg))
		return (0);
	if (check_overflow(arg))
		return (0);
	return (1);
}
