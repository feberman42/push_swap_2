/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_iduxp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:39:32 by feberman          #+#    #+#             */
/*   Updated: 2023/05/30 12:02:35 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_convert_id(char *flags, int width, int precision, va_list args)
{
	long long	value;
	char		padding;
	int			numlen;
	int			printed;

	printed = 0;
	padding = ft_padchar(flags, precision);
	value = (long long)va_arg(args, int);
	numlen = ft_numlen(value, flags, precision);
	printed += numlen;
	if (padding == '0')
		value = ft_putsign(flags, value);
	printed += ft_putpadding_front(width, numlen, flags, padding);
	if (padding == ' ')
		value = ft_putsign(flags, value);
	ft_handle_precision(value, precision);
	if (value != 0 || precision != 0)
		ft_putulong(value);
	printed += ft_putpadding_back(width, numlen, flags);
	return (printed);
}

int	ft_convert_u(char *flags, int width, int precision, va_list args)
{
	unsigned int	value;
	char			padding;
	int				numlen;
	int				printed;

	printed = 0;
	padding = ft_padchar(flags, precision);
	value = va_arg(args, unsigned int);
	numlen = ft_numlen(value, flags, precision);
	printed += numlen;
	if (ft_charin(' ', flags) || ft_charin('+', flags))
		numlen--;
	printed += ft_putpadding_front(width, numlen, flags, padding);
	ft_handle_precision(value, precision);
	if (value != 0 || precision != 0)
		ft_putulong(value);
	printed += ft_putpadding_back(width, numlen, flags);
	return (printed);
}

int	ft_convert_x(char *flags, int width, int precision, va_list args)
{
	unsigned int	value;
	int				printed;
	int				numlen;
	char			padding;

	printed = 0;
	value = va_arg(args, unsigned int);
	numlen = ft_numlen_hex(value, flags, precision);
	printed += numlen;
	padding = ft_padchar(flags, precision);
	if (padding == '0')
		ft_putsign_hex(flags, value);
	printed += ft_putpadding_front(width, numlen, flags, padding);
	if (padding == ' ')
		ft_putsign_hex(flags, value);
	ft_precision_hex(value, precision);
	if (value != 0 || precision != 0)
		ft_putnbr_hex(value, ft_charin('X', flags));
	printed += ft_putpadding_back(width, numlen, flags);
	return (printed);
}

int	ft_convert_nil(char *flags, int width)
{
	int					printed;
	int					numlen;

	printed = 0;
	numlen = 5;
	printed += numlen;
	printed += ft_putpadding_front(width, numlen, flags, ' ');
	ft_putstr_fd("(nil)", 1);
	printed += ft_putpadding_back(width, numlen, flags);
	return (printed);
}

int	ft_convert_p(char *flags, int width, int precision, va_list args)
{
	unsigned long int	value;
	int					printed;
	int					numlen;
	char				padding;

	printed = 0;
	value = va_arg(args, unsigned long int);
	if (value == 0)
		return (ft_convert_nil(flags, width));
	numlen = ft_numlen_hex(value, flags, precision);
	printed += numlen;
	padding = ft_padchar(flags, precision);
	if (padding == '0')
		ft_putsign_hex("#", value);
	printed += ft_putpadding_front(width, numlen, flags, padding);
	if (padding == ' ')
		ft_putsign_hex("#", value);
	ft_precision_hex(value, precision);
	ft_putnbr_hex(value, ft_charin('X', flags));
	printed += ft_putpadding_back(width, numlen, flags);
	return (printed);
}
