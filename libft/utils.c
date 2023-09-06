/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:20:09 by feberman          #+#    #+#             */
/*   Updated: 2023/05/30 12:04:37 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_charin(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_putpadding_front(int width, int len, char *flags, char padding)
{
	int	printed;

	printed = 0;
	while (width - len >= 1 && !ft_charin('-', flags))
	{
		ft_putchar_fd(padding, 1);
		printed++;
		width--;
	}
	return (printed);
}

int	ft_putpadding_back(int width, int len, char *flags)
{
	int	printed;

	printed = 0;
	while (width - len >= 1 && ft_charin('-', flags))
	{
		ft_putchar_fd(' ', 1);
		printed++;
		width--;
	}
	return (printed);
}

int	ft_width(const char *s, va_list args)
{
	int	i;
	int	width;

	i = 0;
	if (s[i] == '*')
	{
		width = (va_arg(args, int));
		return (width);
	}
	else
		return (ft_atoi(s + i));
}

int	ft_precision(const char *s, va_list args)
{
	int	i;

	i = 0;
	if (s[i] != '.')
		return (-1);
	i++;
	if (s[i] == '*')
		return (va_arg(args, int));
	else
		return (ft_atoi(s + i));
}
