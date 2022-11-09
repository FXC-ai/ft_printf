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


int ft_check_type(char c)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (c == LST_TYPES[i])
			return (i);
		i++;		
	}
	return (-1);
}



int ft_printf(const char *str, ...)
{

	size_t	size_str;
	size_t	i;
	int		i_type;
	va_list	args;

	size_str = ft_strlen(str);

	va_start(args, str);



	i = 0;
	while (i < size_str)
	{
		
		if (str[i] != '%')
		{
			if (write(1,&str[i],1) == -1)
				return(-1);
		}
		else
		{
			i_type = ft_check_type(str[i + 1]);

		}
		
		i++;
	}

	int val = va_arg(args, int);

	printf("val = %d\n", val);
	
	val = va_arg(args, int);

	printf("val = %d\n", val);

	va_end(args);

	return 0;
}

int main()
{
	ft_printf("Ce %d caractere a parser\n", 12, 34, 56);


	return 0;
}
