/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:21:42 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/20 12:39:57 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

void	ft_putnbr_hex_fd(unsigned int n, char *base, int fd)
{
	char		display_n_char;
	//char 		*base;

	//base = "0123456789abcdef";
	display_n_char = 0;

	if (n > 0)
	{
		ft_putnbr_hex_fd((n / 16), base,fd);
		display_n_char = base[n % 16];
		ft_putchar_fd(display_n_char, fd);
	}

}

/*
int main()
{
	
	ft_putnbr_hex_fd(17, 1);

	return 0;
}
*/