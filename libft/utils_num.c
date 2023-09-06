/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:55:20 by feberman          #+#    #+#             */
/*   Updated: 2023/05/30 12:05:09 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_numlen(long long num, char *flags, int precision)
{
	int			len;
	int			sign;
	long long	nbr;

	nbr = num;
	sign = (ft_charin('+', flags) || ft_charin(' ', flags));
	if (num < 0 || (num >= 0 && sign))
		sign = 1;
	else
		sign = 0;
	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr /= 10;
	}
	if (num == 0 && precision != 0)
		len = 1;
	if (precision > len)
		len = precision;
	return (len + sign);
}

unsigned long	ft_putsign(char *flags, long long value)
{
	if (ft_charin('+', flags) && value >= 0)
		ft_putchar_fd('+', 1);
	else if (ft_charin(' ', flags) && value >= 0)
		ft_putchar_fd(' ', 1);
	else if (value < 0)
	{
		ft_putchar_fd('-', 1);
		return ((unsigned long)(value *= -1));
	}
	return ((unsigned long)value);
}

void	ft_putulong(unsigned long nbr)
{
	if (nbr > 9)
	{
		ft_putulong(nbr / 10);
		ft_putulong(nbr % 10);
	}
	else
		ft_putchar_fd(nbr + '0', 1);
}

int	ft_handle_precision(long long value, int precision)
{
	int	vallen;
	int	printed;

	printed = 0;
	vallen = 0;
	if (value == 0)
		vallen = 1;
	while (value > 0)
	{
		vallen++;
		value /= 10;
	}
	while (precision > vallen++)
	{
		ft_putchar_fd('0', 1);
		printed++;
	}
	return (printed);
}

char	ft_padchar(char *flags, int precision)
{
	char	padding;

	padding = ' ';
	if (ft_charin('0', flags) && precision == -1)
		padding = '0';
	return (padding);
}
