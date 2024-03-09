
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>

# include "Libft/libft.h"

int ft_printf(const char *str, ...);
int	ft_specifier(va_list arg, char c);
int ft_putchar(char a);
int	ft_string(char *str);
int	ft_address(unsigned long a, int sign);
int	ft_hex(unsigned int a, char c);
int	ft_int(int a);
int	ft_unsigned(unsigned int a);

bool	ft_specifier_cont(const char *str, int i);

#endif