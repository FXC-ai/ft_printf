/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:53:48 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/09 17:58:27 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "libft/libft.h"
#include "libftprintf.h"
void	ft_putstr_cnt(char *str, int *c_count);
void	ft_print_format(const char c_format, va_list *args, int *ptr_c_count);
void	ft_putchar_cnt(char c, int *c_count);


void ft_print_format(const char c_format, va_list *args, int *ptr_c_count)
{
	if (c_format == 'c')
		ft_putchar_cnt(va_arg(*args, int), ptr_c_count);
	else if (c_format == 's')
	{
		ft_putstr_cnt(va_arg(*args, char*), ptr_c_count);
	}
	
}

void	ft_putchar_cnt(char c, int *c_count)
{

	write(1, &c, 1);

	*c_count += 1;
}

void	ft_putstr_cnt(char *str, int *c_count)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
		*c_count += 1;
	}
}

int ft_printf(const char *str, ...)
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
			ft_print_format(str[i + 1], &args, &c_count);
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
	ft_printf("A%c B%s C%c\n", 'a', "assin", 'c');


	return 0;
}
