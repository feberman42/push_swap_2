/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:41:49 by feberman          #+#    #+#             */
/*   Updated: 2023/05/30 11:45:51 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_call_conversion(char *flags, int width, int precision, va_list args)
{
	if (ft_charin('i', flags) || ft_charin('d', flags))
		return (ft_convert_id(flags, width, precision, args));
	else if (ft_charin('u', flags))
		return (ft_convert_u(flags, width, precision, args));
	else if (ft_charin('s', flags))
		return (ft_convert_s(flags, width, precision, args));
	else if (ft_charin('c', flags))
		return (ft_convert_c(flags, width, args));
	else if (ft_charin('x', flags) || ft_charin('X', flags))
		return (ft_convert_x(flags, width, precision, args));
	else if (ft_charin('p', flags))
		return (ft_convert_p(flags, width, precision, args));
	else
		return (ft_convert_percent());
}

int	ft_handle_conversion(char *s, int width, \
	int precision, va_list args)
{
	char	*marker;
	int		i;
	char	*flags;
	int		printed;
	char	*tmp;

	marker = ft_substr(s, ft_strlen(s) - 1, 1);
	printed = 0;
	i = 0;
	while (s[i] != '\0' && ft_charin(s[i], "-0# +"))
		i++;
	tmp = ft_substr(s, 0, i);
	flags = ft_strjoin(tmp, marker);
	free(s);
	printed = ft_call_conversion(flags, width, precision, args);
	free(flags);
	free(marker);
	free(tmp);
	return (printed);
}

int	ft_detect_conversion(const char *s, va_list args)
{
	int		i;
	int		width;
	int		precision;

	i = 1;
	while (s[i] != '\0' && ft_charin(s[i], "-0# +"))
		i++;
	width = ft_width(s + i, args);
	while (s[i] == '*' || ft_isdigit(s[i]))
		i++;
	precision = ft_precision(s + i, args);
	while (ft_charin(s[i], ".*") || ft_isdigit(s[i]))
		i++;
	if (ft_charin(s[i], "cspdiuxX%"))
	{
		return (ft_handle_conversion(ft_substr(s, 1, i), \
			width, precision, args));
	}
	return (0);
}

int	ft_skip_conversion(const char *s)
{
	int	i;

	i = 1;
	while (s[i] != '\0' && ft_charin(s[i], "-0# +"))
		i++;
	while (ft_isdigit(s[i]) || s[i] == '*')
		i++;
	if (s[i] == '.')
		i++;
	while (ft_isdigit(s[i]) || s[i] == '*')
		i++;
	if (ft_charin(s[i], "cspdiuxX%"))
		return (i + 1);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		out;

	va_start(args, s);
	out = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			out += ft_detect_conversion(s + i, args);
			i += ft_skip_conversion(s + i);
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			out++;
			i++;
		}
	}
	va_end(args);
	return (out);
}
