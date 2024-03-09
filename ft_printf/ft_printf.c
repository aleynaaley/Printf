
# include "ft_printf.h"

int ft_putchar(char a)
{
    return (write(1, &a ,1));
}

int	ft_specifier(va_list arg, char c)
{
	if (c == 'u')
		return (ft_unsigned(va_arg((arg), unsigned int)));
	else if (c == 'c')
		return (ft_putchar(va_arg((arg), int)));    // int yerine char dene
	else if (c == 'i' || c == 'd')
		return (ft_int(va_arg((arg), int)));
	else if (c == 'x' || c == 'X')
		return (ft_hex(va_arg((arg), unsigned int), c));
	else if (c == 'p')
		return (ft_address(va_arg((arg), unsigned long), 1));
	else if (c == 's')
		return (ft_string(va_arg((arg), char *)));
	else
		return (ft_string("%%")); // normal fonk da tek % ama bu şekilde iki %% yazıyor birini silip dene
}

bool	ft_specifier_cont(const char *str, int i)
{
	return (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 'd'|| str[i + 1] == 'i' || str[i + 1] == 'u' || str[i + 1] == 'x' 
	|| str[i + 1] == 'X' || str[i + 1] == 'p' || str[i + 1] == 's' || str[i + 1] == '%'));
}
//yüzde işareti bulunduğunda ve yüzden işaretinden sonra geçerli biçimde
// karakteri olduğunda true döndürür

int ft_printf(const char *str, ...)
{
    va_list	arg;
	int		i;
	int		cnt;

	i = -1;
	cnt = 0;
	va_start(arg, str);
	while (str[++i])  //girilen diziyi karakter karakter işler
	{
		if (ft_specifier_cont(str, i))  //yüzde işareti bulunduğunda ve yüzden işaretinden sonra geçerli biçimde karakteri olduğunda true döndürür
			cnt += ft_specifier(arg, str[++i]); //hangi değer olduğunu döndürür rtn ye ekler  
		else                                  // % işaretinden sonra geçerli bir işaret yoksa karaketeri olduğu gibi. yazdırmali 
		{ 
			if (str[i] == '%')
				return (0);
			cnt += write(1, &str[i], 1);
		}	
	}
	va_end(arg);
	return (cnr);    
}



/*
va_start(arg, str); ifadesinde, str’den sonraki argümanları içerir demek, ft_printf fonksiyonuna verilen argümanların,
 str argümanından sonraki tüm argümanları kapsadığı anlamına gelir.

Örneğin, ft_printf("Merhaba %s", "Dünya"); şeklinde bir çağrı yaptığınızda, str “Merhaba %s” olur ve “Dünya” ifadesi 
str’den sonraki argüman olur. Bu durumda, va_start(arg, str); ifadesi arg listesini “Dünya” argümanıyla başlatır.
*/


/*
int main(){
    int a = 42;
    int *b = &a;
    ft_printf("%d  %s %c %X %x %p %i %u %% \n", 1234, "hello" , 'a', 0xA234b, 0xB32f, (void*)b, 26, a);
    printf("%d  %s %c %X %x %p %i %u %% ", 1234, "hello" , 'a', 0xA234b, 0xB32f, (void*)b, 26, a);
}
*/