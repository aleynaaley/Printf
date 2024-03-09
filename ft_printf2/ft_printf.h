/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:16:53 by alerkul           #+#    #+#             */
/*   Updated: 2024/03/09 18:58:39 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_specifier(va_list arg, char c);
int		ft_putchar(char a);
int		ft_string(char *str);
int		ft_address(unsigned long a, int sign);
int		ft_hex(unsigned int a, char c);
int		ft_int(int a);
int		ft_unsigned(unsigned int a);

bool	ft_specifier_cont(const char *str, int i);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);


#endif