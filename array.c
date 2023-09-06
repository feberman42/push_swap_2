/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:09:07 by feberman          #+#    #+#             */
/*   Updated: 2023/09/06 11:51:54 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_array(int argc, char *argv[])
{
	int	size;
	int	*arr;

	size = count_arguments(argc, argv);
	if (size == 0)
		return (0);
	arr = calloc(sizeof(int), size + 1);
	if (!arr)
		return (0);
	if (!populate_arr(argc, argv, arr))
	{
		free(arr);
		return (error_ptr());
	}
	arr[0] = size;
	if (has_doubles(arr))
	{
		free(arr);
		return (error_ptr());
	}
	return (arr);
}

int	populate_arr(int argc, char *argv[], int *arr)
{
	int		i;
	int		j;
	int		index;
	char	**split;

	index = 1;
	i = 1;
	while (i < argc)
	{
		split = ps_split(argv[i++]);
		j = 0;
		while (split[j])
		{
			if (!check_arg(split[j]))
			{
				free_split(split, 0);
				return (0);
			}
			else
				arr[index++] = ft_atoi(split[j]);
			j++;
		}
		free_split(split, 0);
	}
	return (1);
}

void	sort_arr(int *arr)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	while (i <= arr[0])
	{
		j = i + 1;
		while (j <= arr[0])
		{
			if (arr[j] < arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
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

int	get_index(int *arr, int value)
{
	int	i;

	i = 1;
	while (arr[i] != value)
		i++;
	return (i);
}