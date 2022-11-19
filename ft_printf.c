/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:38:20 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/19 11:29:05 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

static void	ft_print_format(const char c_format, va_list args, int *c_count)
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
		ft_print_hex(args, c_count);
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

	count = ft_printf("ft_printf : B:%s C:%c D:%d E:%p\n", "assin", 'c', 2147463647, &non_util3);
	count1 = printf("   printf : B:%s C:%c D:%d E:%p\n", "assin", 'c', 2147463647, &non_util3);
	printf("\n");
	printf("count ft_printf = %d\n", count);
	printf("count    printf = %d", count1);

	//0xa7ffeedcbba61
	//0x7ffeedcbba61


	return 0;
}