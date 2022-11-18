/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:38:20 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/18 23:16:00 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "libft/libft.h"
#include "libftprintf.h"


void	ft_print_nbr(va_list args, int *c_count)
{
	int nbr_to_print;

	nbr_to_print = va_arg(args, int);
	ft_putnbr_fd(nbr_to_print, 1);
	*c_count += ft_strlen(ft_itoa(nbr_to_print));
}

void	ft_print_hex(unsigned long ptr_to_print)
{
	//char c_test = (ptr_to_print % 16) + 48;

	int	mod;
	int tab[30];
	int	i;
	char *base = "0123456789abcdef";


	printf("\nptr_to_print = %lu", ptr_to_print);
	printf("\nptr_to_print = %lx\n", ptr_to_print);

	//ptr_to_print = 4294967295;

	i = 0;
	while(ptr_to_print > 10)
	{
		mod = ptr_to_print % 16;
		ptr_to_print = ptr_to_print / 16;
		tab[i] = mod;
		i++;
		
	}

	while (i >= 0)
	{
		write (1, &base[tab[i]], 1);
		i--;
	}

}


void	ft_print_format(const char c_format, va_list args, int *c_count)
{
	if (c_format == 'c')
	{
		char char_to_print = va_arg(args, int);
		ft_putchar_fd(char_to_print, 1);
		*c_count += 1;
	}
	else if (c_format == 's')
	{
		char *str_to_print = va_arg(args, char *);
		ft_putstr_fd(str_to_print, 1);
		*c_count += ft_strlen(str_to_print);
	}
	else if (c_format == 'd')
	{
		ft_print_nbr(args, c_count);
	}
	else if (c_format == 'p')
	{
		unsigned long ptr_to_print = va_arg(args, unsigned long);
		ft_print_hex(ptr_to_print);
	}
	
}


int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	args;
	int		c_count;

	c_count = 0;
	va_start(args, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_print_format(str[i + 1], args, &c_count);
			i++;
		}
		else
		{
			write(1,&str[i],1);
			c_count++;
		}
		i++;
	}
	va_end(args);
	return c_count;
}

int main()
{
	int count;
	int count1;

	char non_util2;
	non_util2 = '0';

	char non_util3;
	non_util3 = '0';	

	char non_util6;
	non_util6 = '0';

	printf("non : %lu\n", sizeof(&non_util2));

	count = ft_printf("B%s C%c D%d E%p\n", "assin", 'c', 2147463647, &non_util6);
	count1 = printf("B%s C%c D%d E%p\n", "assin", 'c', 2147463647, &non_util6);
	printf("count ft_printf = %d\n", count);
	printf("count    printf = %d", count1);


	return 0;
}