# int printf(const char *format, ...);
printf fonksiyonu int değer döndürür. döndürdüğü değeri ekrana çıktı olarak vermez. döndürdüğü değer ekrana çıktı olarak verdiği karakterlerin toplam sayısıdır  yani bir int değeridir.

#  Variadic Fonksiyonlar

Variadic fonksiyonlar (değişken fonksiyonlar) , değişken sayıda argüman alabilen işlevlerdir . C programlamada değişken bir işlev programa esneklik katar. Bir sabit argüman alır ve daha sonra herhangi bir sayıda argüman iletilebilir. Variadik fonksiyon en az bir sabit değişkenden ve ardından son parametre olarak bir üç noktadan (…) oluşur. bu tür fonksiyonları tanımlamak için `<stdarg.h>` başlık dosyasındaki `va_list`, `va_start`, `va_arg`, ve `va_end` gibi makroları kullanırız. 

```bash
int işlev_adı(veri_tipi değişken_adı, ...);
```

Makro, C ve diğer birçok programlama dilinde, belirli birer metin bloğunu tanımlayan ve bir isimle çağrıldığında bu metin bloğunu yerine koyan bir programlama yapı elemanıdır. C dilinde makrolar, #define ön işlemci direktifi kullanılarak tanımlanır.
```
// Basit bir makro tanımı
#define KARE(x) ((x) * (x))

int main() {
    int sayi = 5;
    int kareSonucu = KARE(sayi);
```

- `va_list`: Bu yapı değişken sayıda argümanlara erişim sağlamak için kullanılan bir türdür. Bu tür, argümanların listesini temsil eder. va_list'in iç yapısı genellikle derleyici ve sistem tarafından gizli tutulur, ve bu yapıya doğrudan erişim sağlamak mümkün değildir.Tür genellikle fonksiyon içerisinde kullanılır.
  
- `va_start(va_list args, argN)` : Bu, değişken fonksiyon argümanlarına erişim sağlar.Burada *va_list* değişken işlevdeki son sabit argümanın işaretçisi olacaktır.*argN* değişken fonksiyondaki son sabit argümandır.Yani *va_start* makrosu *va_list* yapısını başlatır ve bu yapı üzerinden değişke  n sayıda argümanlara erişim sağlanabilir hale gelir(fonksiyonun argümanlarını işlemek için hazırlık yapar).*va_start* makrosu kullanılmadan önce *va_list* türü başlatılamaz.
  
- `va_arg(va_list args, type)` : *va_list* *va_start* ile başlatılan variadic argüman listesini temsil eden bir yapıdır *type* Erişilmek istenen argümanın türüdür.*va_list* ile argümanlara erişim için kullanılıyor.
  
- `va_end(va_list args)`:Değişken sayıda argüman alan fonksiyonların sonunda va_list'i temizlemek için kullanılır. Bu makro, va_start ile başlatılan va_list'i sıfırlar ve gerektiğinde bellek kaynaklarını serbest bırakır.Bu, özellikle bellek sızıntılarını önlemek ve değişken sayıda argüman alan fonksiyonlarını güvenli bir şekilde kullanmak için önemlidir.
  
- `va_copy(va_list hedefi, va_list kaynağı)`:Bu makro, bir va_list'i başka bir va_list ile aynı duruma getirir, böylece aynı argüman listesine erişim sağlar.Bu, özellikle bir va_list'in değerini başka bir va_list'e kopyalamak istediğiniz durumlarda kullanışlıdır.

nt:
*va_list* türü, derleyicinin ve platformun implementasyonuna bağlı olarak, argümanların saklandığı bir türdür. Derleyici ve platform, değişken sayıda argümanları geçiş şeklini (calling convention) ve bellek düzenini belirleyerek va_list'i kullanır. *va_start*,*va_arg*, ve *va_end* makroları, bu iç yapıya uygun şekilde *va_list*'i manipüle eder.

Bu nedenle, *va_list* türünün iç yapısına dair kesin bir bilgiye sahip olmamak önemlidir. Programcı, sadece va_list türünü kullanarak argümanlara erişir ve manipüle eder. Bu işlemleri gerçekleştirmek için *va_start*, *va_arg*, ve *va_end* gibi makrolar kullanılır.

 örnek
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
 ```bash
int result = sum_variadic(3, 1, 2, 3);
printf("The sum is: %d", result);
çıktı: The sum is: 6
 ```
# Makro ve Fonksiyonalar arasındaki fark

Makro ve fonksiyonlar, C programlama dilinde kodunuzu yapılandırmak ve tekrar kullanılabilirliği artırmak için kullanılan iki farklı kavramdır. İşte makro ve fonksiyonlar arasındaki bazı temel farklar:

- Çalışma Zamanı:
  - Makro: Makrolar, derleme zamanında işlenir. Yani, kod derlendiğinde, makro çağrıları, makro gövdelerine doğrudan yerine geçirilir.
  - Fonksiyon: Fonksiyonlar, çalışma zamanında işlenir. Yani, kod çalıştırıldığında, fonksiyonlar çağrılarak çalışır.

- Yerine Geçme:
  - Makro: Makro çağrıları, genellikle dosyada veya kaynak kodda göründükleri şekilde yerine geçer. Bu, makro kullanımının doğrudan yerine geçme (substitution) olduğu anlamına gelir.
  - Fonksiyon: Fonksiyonlar, çağrıldıkları noktada çalıştırılır ve geri dönüş değeri üzerinden etkileşim sağlanır.

- Tanımlama ve Kapsam:
  - Makro: Makrolar #define ifadesiyle tanımlanır ve genellikle programın her yerinde geçerlidir. Tanımlar genellikle tek satırda olur.
  - Fonksiyon: Fonksiyonlar, genellikle ayrı bir blokta tanımlanır ve bu blok kodun başka yerlerinden çağrılır. Fonksiyonlar kendi kapsam alanlarına sahiptirler.

- Tip Güvenliği:
  - Makro: Makrolar genellikle tip güvenli değildir. Makro gövdelerinde doğrudan değer yerine geçirildiği için tip uyumsuzluklarına yol açabilir.
  - Fonksiyon: Fonksiyonlar genellikle tip güvenlidir. Fonksiyonların parametreleri ve dönüş değerleri için belirli bir tür belirtilir, bu nedenle tip uyumsuzluğu daha az olasılıklıdır.

- Debugging (Hata Ayıklama):
  - Makro: Hata ayıklama süreci, makro kullanımında zor olabilir çünkü derleme zamanında işlenir ve genellikle doğrudan kodda göründükleri gibi değil, yerine geçmiş halleriyle hata mesajları alınır.
  - Fonksiyon: Fonksiyonlar, hata ayıklama sürecini kolaylaştırabilir çünkü kod parçacıkları izlenebilir, adlandırılabilir ve işlevsellik açısından açıkça anlaşılabilir.

```
typedef struct {
    // ... va_list'in iç yapısı, platforma bağlı olarak değişebilir ...
} va_list;

#define va_start(ap, last_arg) // ... va_list'i başlatan makro ...
#define va_arg(ap, type)       // ... va_list'ten argüman okuyan makro ...
#define va_end(ap)             // ... va_list'i temizleyen makro ...
```

#  putnbr()
neden yetersiz ? 
Örneğin, %d bir tamsayıyı temsil eder, %s bir karakter dizisini temsil eder. printf() fonksiyonu, biçim belirleyicileri kullanılarak farklı veri tiplerini ve biçimleri çıktıya yazdırabilir.

ft_putnbr_fd(), spesifik olarak bir tamsayıyı dosyaya karakter dizisi olarak yazdırmak için tasarlanmıştır. Biçim belirleyicileri kullanılmaz ve sadece tamsayı değerini karakterlere dönüştürür.
printf() fonksiyonu, çıktıyı standart çıkışa (stdout) veya başka bir dosya tanımlayıcısına yönlendirmek için kullanılabilir.

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


# Boolean Değişken Tanımlama
C dilinde boolean veri tipi doğrudan desteklenmez; ancak, bu tür bir mantıksal durumu temsil etmek için  `stdbool.h ` başlık dosyasında tanımlanan bool türünü kullanabiliriz. 

```
#include <stdbool.h>
int main(){
	bool myBooleanVariable;
	myBooleanVariable = true;
```
Bu şekilde, stdbool.h başlık dosyasını dahil ederek ve bool türünü kullanarak C dilinde boolean bir değişken tanımlayabilir ve kullanabiliriz.

# Printf fonksiyonunda Buffer yönetimi
C dilinde printf() fonksiyonu, çıktıyı standart çıkış akımına (genellikle ekran) yazdırmak için kullanılır. Bu fonksiyonun içinde, çıktı verileri bir tampon (buffer) üzerinde geçici olarak depolanır(genellikle ram ) ve daha sonra bu tampon standart çıkışa aktarılır.
- Tampon (Buffer) Boyutu: printf() fonksiyonunun bir tampon boyutu vardır. Bu, geçici olarak depolanan verilerin miktarını belirler. Tampon boyutu C dilinde derleyiciden derleyiciye değişebilir. Standart C kütüphanesine göre, printf() fonksiyonu genellikle 1024 bayt büyüklüğünde bir tampon kullanır. Ancak, bu değer değişebilir.
 Çıktı Formatlaması: printf() fonksiyonu, belirtilen formatlama dizesine göre çıktıyı oluşturur. Verilen argümanlar, bu formatlama dizesine göre işlenir ve geçici bir tampona yerleştirilir.
 
-Tampona Yazma: Çıktı verileri, formatlama işleminden sonra oluşturulan geçici tampona yazılır.
 
-Tamponun Boşaltılması: Tampon, belirli bir boyuta ulaştığında veya printf() fonksiyonu çağrıldığında otomatik olarak boşaltılır. Bu, tamponun içindeki verilerin standart çıkışa (örneğin, ekran) yazılmasını sağlar.
 
-Manuel Boşaltma: Bazı durumlarda, programcı fflush(stdout) fonksiyonunu kullanarak tamponu manuel olarak boşaltabilir. Bu, çıktının hemen standart çıkışa yazılmasını sağlar.

# Printf fonksiyonu ile ft_printf arasındaki farklar
- Biçimlendirme seçenekleri: Bu ft_printf fonksiyonu, sadece %c, %d, %i, %u, %x, %X, %p, %s ve %% biçimlendirme seçeneklerini destekler. Ancak, standart printf fonksiyonu, çok daha fazla biçimlendirme seçeneği sunar, örneğin %f (float), %e (bilimsel notasyon), %g (genel format), %o (oktal), %n (yazılan karakter sayısı), vb.
- Alan genişliği ve hassasiyet: Standart printf fonksiyonu, alan genişliği ve hassasiyet belirticilerini destekler. Örneğin, %10.2f ifadesi, bir float değerini en az 10 karakter genişliğinde ve ondalık noktadan sonra 2 basamak hassasiyetle yazdırır. Ancak, bu ft_printf fonksiyonu, bu özellikleri desteklemez.
- Bayraklar: Standart printf fonksiyonu, çeşitli bayrakları destekler, örneğin - (sol hizalama), + (işaret belirtme),   (boşluk), 0 (sıfır dolgu), # (alternatif biçim). Ancak, bu ft_printf fonksiyonu, bu bayrakları desteklemez.
- Uzunluk belirticileri: Standart printf fonksiyonu, çeşitli uzunluk belirticilerini destekler, örneğin l (long), ll (long long), h (short), hh (char), L (long double). Ancak, bu ft_printf fonksiyonu, bu belirticileri desteklemez.
- Buffer Yönetimi : Standart printf fonksiyonu, genellikle bir çıktı tamponu kullanır. Bu, printf’in çıktısını hemen yazdırmak yerine bir tampona yazdığı ve tampon dolana kadar veya belirli bir durumda (örneğin, bir yeni satır karakteri görüldüğünde veya fflush fonksiyonu çağrıldığında) tamponun içeriğini standart çıktıya boşalttığı anlamına gelir. Bu, performansı artırabilir çünkü sistem çağrılarının sayısını azaltır.
Öte yandan, bu ft_printf fonksiyonu, her karakteri veya dizeyi hemen standart çıktıya yazdırır. Bu, write sistem çağrısını her seferinde çağırır, bu da daha fazla sistem çağrısı anlamına gelir ve bu da performansı düşürebilir.
Bu nedenle, bu ft_printf fonksiyonu, tamponlama kullanmayan daha basit bir yaklaşımı benimserken, standart printf fonksiyonu genellikle tamponlama kullanır
# Specifier seçenekleri ve Flagler 

Biçimlendirme seçenekleri, printf gibi bir fonksiyonda kullanılan ve çıktının nasıl görüneceğini belirleyen özel karakterler veya karakter dizileridir. Örneğin, %d bir tamsayıyı, %f bir kayan noktalı sayıyı, %s bir dizeyi ve %c bir karakteri temsil eder.

Flag ise, printf gibi bir fonksiyonda kullanılan ve çıktının biçimlendirilmesini daha da özelleştiren özel karakterlerdir. Örneğin, - flag’ı sol hizalamayı, + flag’ı pozitif sayıların önünde artı işareti olmasını, 0 flag’ı sayının başındaki boşlukların sıfır ile doldurulmasını sağlar. Bu flag’lar, genellikle yüzde işareti (%) ve biçimlendirme karakteri arasında yer alır. Örneğin, printf ifadesinde %+d, pozitif bir tamsayının önünde artı işareti olmasını sağlar.

%[flags][width][.precision][length]specifier
# 
	%c tek bir karakter yazdırır.
	%s bir karakter dizisi yazdırır.
	%p Void * pointer argümanını hexadecimal biçiminde yazdırır.
	%d 10 tabanında decimal sayı yazdırır.
	%i 10 tabanında tam sayı yazdırır.
	%u 10 tabanında işaretsiz decimal sayı yazdırır.
	%x hexadecimal sayıyı (16 tabanında) küçük harfler ile yazdırır.
	%X hexadecimal sayıyı (16 tabanında) büyük harfler ile yazdırır.
	%% yüzde işareti yazdırır.


# Write fonksiyonu
write fonksiyonu, başarılı olduğunda yazılan bayt sayısını döndürür. Ancak, bir hata durumunda, -1 değerini döndürür ve errno hatayı belirtmek üzere ayarlanır.
write fonksiyonunun istenen tüm baytları yazmayabilir. Bu tür kısmi yazmalar çeşitli nedenlerle olabilir; örneğin, disk cihazında istenen tüm baytları yazmak için yeterli alan olmaması veya bir sinyal işleyicisi tarafından bir write çağrısı, istenen tüm baytları aktarmadan önce bazı baytları aktardıktan sonra kesilmesi durumunda1. Kısmi bir yazma durumunda, çağıran başka bir write çağrısı yaparak kalan baytları aktarabilir

# Litbool komutu
libtool C dilinde kütüphane oluştururken kullanılan bir araçtırlibtool, paylaşılan kütüphanelerin karmaşıklığını gizleyen ve tutarlı, taşınabilir bir arayüz sağlayan genel bir kütüphane destek betiği olarak tanımlanabilir12.

libtool’un temel işlevleri şunlardır:

- Nesne Dosyaları Oluşturma: libtool’u kullanarak, platforma özgü derleyici bayraklarına ihtiyaç duymadan nesne dosyaları oluşturabilirsiniz.
- Kütüphaneleri Bağlama (Linking): libtool, hem statik hem de dinamik kütüphaneleri bağlamak için kullanılabilir. Bu, platforma özgü derleyici ve bağlayıcı bayraklarını gizler.
- Yürütülebilir Dosyaları Bağlama (Linking): libtool, yürütülebilir dosyaları bağlamak için de kullanılabilir. Bu, yürütülebilir dosyanın hangi kütüphanelere bağlı olduğunu belirler.
- Kütüphaneleri Yükleme: libtool, kütüphanelerin doğru yere yüklenmesini sağlar.
- Yürütülebilir Dosyaları Yükleme: libtool, yürütülebilir dosyaların doğru yere yüklenmesini sağlar.

