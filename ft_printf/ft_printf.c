/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:16:11 by alerkul           #+#    #+#             */
/*   Updated: 2024/03/11 08:56:16 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char a)
{
	return (write(1, &a, 1));
}

int	ft_specifier(va_list arg, char c)
{
	if (c == 'u')
		return (ft_unsigned(va_arg((arg), unsigned int)));
	else if (c == 'c')
		return (ft_putchar(va_arg((arg), int)));
	else if (c == 'i' || c == 'd')
		return (ft_int(va_arg((arg), int)));
	else if (c == 'x' || c == 'X')
		return (ft_hex(va_arg((arg), unsigned int), c));
	else if (c == 'p')
		return (ft_address(va_arg((arg), unsigned long), 1));
	else if (c == 's')
		return (ft_string(va_arg((arg), char *)));
	else
		return (ft_string("%"));
}

bool	ft_specifier_cont(const char *str, int i)
{
	return (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 'd' || str[i
				+ 1] == 'i' || str[i + 1] == 'u' || str[i + 1] == 'x' || str[i
				+ 1] == 'X' || str[i + 1] == 'p' || str[i + 1] == 's' || str[i
				+ 1] == '%'));
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (ft_specifier_cont(str, i))
			cnt += ft_specifier(arg, str[++i]);
		else
		{
			if (str[i] == '%')
				++i;
			cnt += write(1, &str[i], 1);
		}
		++i;
	}
	va_end(arg);
	return (cnt);
}
