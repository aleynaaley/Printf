/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:16:36 by alerkul           #+#    #+#             */
/*   Updated: 2024/03/09 16:52:10 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int a)
{
	int	ret;

	ret = 0;
	if (a >= 10)
		ret += ft_unsigned(a / 10);
	write(1, &"0123456789"[a % 10], 1);
	return (ret + 1);
}

int	ft_int(int a)
{
	char	*res;
	int		chr;

	res = ft_itoa(a);
	chr = ft_strlen(res);
	ft_putstr_fd(res, 1);
	free(res);
	return (chr);
}

int	ft_hex(unsigned int a, char c)
{
	int	ret;

	ret = 0;
	if (a >= 16)
		ret += ft_hex(a / 16, c);
	if (c == 'X')
		write(1, &"0123456789ABCDEF"[a % 16], 1);
	if (c == 'x')
		write(1, &"0123456789abcdef"[a % 16], 1);
	return (ret + 1);
}

int	ft_address(unsigned long a, int sign)
{
	int	ret;

	ret = 0;
	if (sign == 1)
	{
		ret += write(1, "0x", 2);
		sign = 0;
	}
	if (a >= 16)
		ret += ft_address(a / 16, 0);
	write(1, &"0123456789abcdef"[a % 16], 1);
	return (ret + 1);
}

int	ft_string(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	else
		return (write(1, str, ft_strlen(str)));
}