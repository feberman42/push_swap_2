/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:18:41 by feberman          #+#    #+#             */
/*   Updated: 2023/05/30 12:05:11 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_numlen_hex(unsigned long int value, char *flags, int precision)
{
	int	sign;
	int	len;

	sign = 0;
	if (value > 0 && ft_charin('#', flags))
		sign = 2;
	if (ft_charin('p', flags))
		sign = 2;
	len = 0;
	if (value == 0 && precision != 0)
		len = 1;
	while (value != 0)
	{
		len++;
		value /= 16;
	}
	if (precision > len)
		len = precision;
	return (len + sign);
}

void	ft_precision_hex(unsigned long int value, int precision)
{
	int	vallen;

	vallen = 0;
	if (value == 0)
		vallen = 1;
	while (value > 0)
	{
		vallen++;
		value /= 16;
	}
	while (precision > vallen++)
		ft_putchar_fd('0', 1);
}

void	ft_putsign_hex(char *flags, unsigned long int value)
{
	if (value == 0)
		return ;
	if (ft_charin('#', flags))
	{
		if (ft_charin('X', flags))
			ft_putstr_fd("0X", 1);
		else
			ft_putstr_fd("0x", 1);
	}
}

void	ft_putnbr_hex(unsigned long int value, int cap)
{
	char	*digits;

	if (cap)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (value > 15)
	{
		ft_putnbr_hex(value / 16, cap);
		ft_putnbr_hex(value % 16, cap);
	}
	else
		ft_putchar_fd(digits[value], 1);
}
