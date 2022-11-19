#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

void	ft_putnbrhex_fd(unsigned long n, int fd);
void	ft_print_nbr(va_list args, int *c_count);
void	ft_print_hex(va_list args, int *c_count);
void	ft_putnbrhex_fd(unsigned long n, int fd);
int		ft_printf(const char *str, ...);


#endif