/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_sc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:06:53 by feberman          #+#    #+#             */
/*   Updated: 2023/05/30 12:02:41 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_convert_s(char *flags, int width, int precision, va_list args)
{
	char	*str;
	int		strlen;
	int		printed;

	printed = 0;
	str = va_arg(args, char *);
	if (str == 0)
	{
		if (precision >= 6 || precision == -1)
			str = ft_strdup("(null)");
		else
			str = ft_strdup("");
	}
	else
		str = ft_substr(str, 0, precision);
	strlen = ft_strlen(str);
	printed += strlen;
	printed += ft_putpadding_front(width, strlen, flags, ' ');
	ft_putstr_fd(str, 1);
	printed += ft_putpadding_back(width, strlen, flags);
	free(str);
	return (printed);
}

int	ft_convert_c(char *flags, int width, va_list args)
{
	unsigned char	c;
	int				printed;

	c = (unsigned char)va_arg(args, int);
	printed = 1;
	printed += ft_putpadding_front(width, 1, flags, ' ');
	ft_putchar_fd(c, 1);
	printed += ft_putpadding_back(width, 1, flags);
	return (printed);
}

int	ft_convert_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
