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
