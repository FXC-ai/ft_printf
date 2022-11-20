#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

# define BASEHEX_MAJ "0123456789ABCDEF"
# define BASEHEX_MIN "0123456789abcdef"


void	ft_print_nbr(va_list args, int *ptr_c_count);
void	ft_print_ptr(va_list args, int *ptr_c_count);

int		ft_printf(const char *str, ...);
void	ft_print_str(va_list args, int *ptr_c_count);
void	ft_putnbrlong_fd(long n, int fd);
void	check_leaks();
void	ft_print_chr(va_list args, int *ptr_c_count);
void	ft_print_prcent(int *ptr_c_count);

void	ft_print_uint(va_list args, int *ptr_c_count);


void	ft_print_hex(va_list args, char *base, int *ptr_c_count);

#endif