/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:44:29 by feberman          #+#    #+#             */
/*   Updated: 2023/05/30 11:45:34 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int				ft_convert_id(char *flags, int width, \
								int precision, va_list args);
int				ft_convert_u(char *flags, int width, \
								int precision, va_list args);
int				ft_convert_s(char *flags, int width, \
								int precision, va_list args);
int				ft_convert_c(char *flags, int width, \
								va_list args);
int				ft_convert_x(char *flags, int width, \
								int precision, va_list args);
int				ft_convert_p(char *flags, int width, \
								int precision, va_list args);
int				ft_convert_percent(void);
int				ft_charin(char c, char *set);
int				ft_numlen(long long num, char *flags, int precision);
unsigned long	ft_putsign(char *flags, long long value);
void			ft_putulong(unsigned long nbr);
int				ft_putpadding_front(int width, int len, \
								char *flags, char padding);
int				ft_putpadding_back(int width, int len, char *flags);
int				ft_handle_precision(long long value, int precision);
void			ft_precision_hex(unsigned long int value, int precision);
char			ft_padchar(char *flags, int precision);
int				ft_numlen_hex(unsigned long int value, \
								char *flags, int precision);
void			ft_putsign_hex(char *flags, unsigned long int value);
void			ft_putnbr_hex(unsigned long int value, int cap);
int				ft_width(const char *s, va_list args);
int				ft_precision(const char *s, va_list args);

#endif