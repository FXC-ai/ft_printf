# ft_printf

```c
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

void print_char(va_list args) {
    char c = (char)va_arg(args, int);
    write(1, &c, 1);
}

void print_string(va_list args) {
    char *s = va_arg(args, char *);
    while (*s) {
        write(1, s, 1);
        s++;
    }
}

void print_number_helper(int n, int base, const char *digits) {
    if (n >= base) {
        print_number_helper(n / base, base, digits);
    }
    write(1, &digits[n % base], 1);
}

void print_int(va_list args) {
    int num = va_arg(args, int);
    if (num < 0) {
        write(1, "-", 1);
        num = -num;
    }
    print_number_helper(num, 10, "0123456789");
}

void print_uint(va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    print_number_helper(num, 10, "0123456789");
}

void print_hex(va_list args, bool uppercase) {
    unsigned int num = va_arg(args, unsigned int);
    const char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    print_number_helper(num, 16, digits);
}

void print_pointer(va_list args) {
    uintptr_t ptr = (uintptr_t)va_arg(args, void *);
    write(1, "0x", 2);
    print_number_helper(ptr, 16, "0123456789abcdef");
}

int ft_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    print_char(args);
                    break;
                case 's':
                    print_string(args);
                    break;
                case 'd':
                case 'i':
                    print_int(args);
                    break;
                case 'u':
                    print_uint(args);
                    break;
                case 'x':
                    print_hex(args, false);
                    break;
                case 'X':
                    print_hex(args, true);
                    break;
                case 'p':
                    print_pointer(args);
                    break;
                default:
                    write(1, "%", 1);
                    write(1, format, 1);
                    break;
            }
        } else {
            write(1, format, 1);
        }
        format++;
    }

    va_end(args);

    return 0; // Le nombre de caractères écrits n'est pas retourné dans cet exemple simplifié
}

int main() {
    ft_printf("Hello, %s! The number is %d, unsigned is %u, hex is %x (uppercase: %X), and the address is %p\n", "world", -42, 42, 42, 42, &main);
    return 0;
}
```
