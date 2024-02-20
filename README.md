#  Variadic Fonksiyonlar

Variadic fonksiyonlar (değişken fonksiyonlar) , değişken sayıda argüman alabilen işlevlerdir . C programlamada değişken bir işlev programa esneklik katar. Bir sabit argüman alır ve daha sonra herhangi bir sayıda argüman iletilebilir. Variadik fonksiyon en az bir sabit değişkenden ve ardından son parametre olarak bir üç noktadan (…) oluşur. bu tür fonksiyonları tanımlamak için `<stdarg.h>` başlık dosyasındaki `va_list`, `va_start`, `va_arg`, ve `va_end` gibi makroları kullanırız. 
```bash
int işlev_adı(veri_tipi değişken_adı, ...);
```

- `va_list`: stdarg.h başlık dosyasında tanımlanmış olan bir yapı (structure) veya türün adıdır. Bu yapı, bir veya daha fazla değişken sayıda argümanı taşımak için kullanılır. va_list'in iç yapısı genellikle derleyici ve sistem tarafından gizli tutulur, ve bu yapıya doğrudan erişim sağlamak mümkün değildir.


- `va_start(va_list ap, argN)` : Bu, değişken fonksiyon argümanlarına erişim sağlar.Burada *va_list* değişken işlevdeki son sabit argümanın işaretçisi olacaktır.*argN* değişken fonksiyondaki son sabit argümandır.Yani *va_start* makrosu *va_list* yapısını başlatır ve bu yapı üzerinden değişken sayıda argümanlara erişim sağlanabilir hale gelir. 
- `type va_arg(va_list ap, type)` : *va_list* *va_start* ile başlatılan variadic argüman listesini temsil eden bir yapıdır *type* Erişilmek istenen argümanın türüdür.
- `va_end(va_list ap)`:
- `va_copy(va_list hedefi, va_list kaynağı)`:

Makro, genellikle bir belirteç veya sembolik ad ile ilişkilendirilmiş, bir ya da daha fazla ifadeyi içeren bir programlama yapısıdır. Makrolar, programcılara tekrar eden kod bloklarını kısaltmak, kodu daha okunabilir hale getirmek ve programcılara belirli bir görevi gerçekleştirmek için kullanılan özel bir dil sunmak amacıyla kullanılır.

C programlama dilinde makrolar, #define ön işlemci direktifi ile tanımlanır. Ön işlemci, kodu derleme öncesinde belirli değişikliklere tabi tutan bir programın parçasıdır. Bir makro, belirli bir sembolün bir ifade ile değiştirilmesini sağlar.

- örnek
 ```bash
int sum_variadic(int count, ...)
{
    va_list args;

    va_start(args, count);
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}
 ```


#  putnbr()
 ```bash

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd((nbr % 10) + '0', fd);
	}
	else
		ft_putchar_fd(nbr + '0', fd);
}

 ```
#  putstr()


 ```bash

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		write(fd, &(*s), 1);
		s++;
	}
}

 ```


# Printf
int
     printf(const char * restrict format, ...);DESCRIPTION
     The printf() family of functions produces output according to a format as
     described below.  The printf() and vprintf() functions write output to
     stdout, the standard output stream; fprintf() and vfprintf() write output
     to the given output stream; dprintf() and vdprintf() write output to the
     given file descriptor; sprintf(), snprintf(), vsprintf(), and vsnprintf()
     write to the character string str; and asprintf() and vasprintf() dynami-
     cally allocate a new string with malloc(3).

     Extended locale versions of these functions are documented in
     printf_l(3).  See xlocale(3) for more information.

     These functions write the output under the control of a format string
     that specifies how subsequent arguments (or arguments accessed via the
     variable-length argument facilities of stdarg(3)) are converted for out-
     put

     RETURN VALUES
     These functions return the number of characters printed (not including
     the trailing `\0' used to end output to strings), except for snprintf()
     and vsnprintf(), which return the number of characters that would have
     been printed if the size were unlimited (again, not including the final
     `\0').  These functions return a negative value if an error occurs.

EXAMPLES
     To print a date and time in the form ``Sunday, July 3, 10:02'', where
     weekday and month are pointers to strings:

           #include <stdio.h>
           fprintf(stdout, "%s, %s %d, %.2d:%.2d\n",
                   weekday, month, day, hour, min);

     To print pi to five decimal places:

           #include <math.h>
           #include <stdio.h>
           fprintf(stdout, "pi = %.5f\n", 4 * atan(1.0));

     To allocate a 128 byte string and print into it:

           #include <stdio.h>
           #include <stdlib.h>
           #include <stdarg.h>
           char *newfmt(const char *fmt, ...)
           {
                   char *p;
                   va_list ap;
                   if ((p = malloc(128)) == NULL)
                           return (NULL);
                   va_start(ap, fmt);
                   (void) vsnprintf(p, 128, fmt, ap);
                   va_end(ap);
                   return (p);
           }
