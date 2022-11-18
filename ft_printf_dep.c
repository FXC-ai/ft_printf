/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:53:48 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/18 19:21:16 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "libft/libft.h"
#include "libftprintf.h"
//void	ft_putstr_cnt(char *str, int *c_count);
void	ft_print_format(const char c_format, va_list *args, int *c_count);
//void	ft_putchar_cnt(char c, int *c_count);


void	ft_print_format(const char c_format, va_list *args, int *c_count)
{
	if (c_format == 'c')
	{
		ft_putchar(va_arg(*args, int));
	}
	else if (c_format == 's')
	{
		ft_putstr(va_arg(*args, char*));
		*c_count += ft_strlen(va_arg(*args, char*));
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
	int count;

	
	count = ft_printf("A%c B%s C%c\n", 'a', "assin", 'c');
	printf("count = %d", count);


	return 0;
}
