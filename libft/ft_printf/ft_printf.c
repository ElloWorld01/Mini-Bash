/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elombard <elombard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:24:11 by elombard          #+#    #+#             */
/*   Updated: 2023/02/24 19:55:10 by elombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	space(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;

	va_start(args, format);
	size = 0;
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			++size;
		}
		else
		{
			++format;
			size += print_cases(format, args);
		}
		++format;
	}
	va_end(args);
	return (size);
}

int	print_cases(const char *format, va_list args)
{
	if (*format == '\0' || space(*format))
		return (only_percent_case(format));
	if (*format == '%')
		return (percent_percent_case());
	if (*format == 'c')
		return (char_case(va_arg(args, int)));
	if (*format == 'd' || *format == 'i')
		return (int_case(va_arg(args, int)));
	if (*format == 's')
		return (string_case(va_arg(args, char *)));
	if (*format == 'u')
		return (unsigned_int_case(va_arg(args, unsigned int)));
	if (*format == 'p')
		return (pointer_case(va_arg(args, uintptr_t)));
	if (*format == 'x')
		return (hexa_lower_case(va_arg(args, unsigned int)));
	if (*format == 'X')
		return (hexa_upper_case(va_arg(args, unsigned int)));
	return (0);
}
