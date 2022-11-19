/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:21:42 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/19 21:58:32 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

void	ft_putnbr_hex_fd(int n, int fd)
{
	int	display_n;
	char		display_n_char;
	char 		*base;

	base = "0123456789abcdef";
	display_n_char = 0;

	if (n < 0)
		n = -n;
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n >= 1)
	{
		display_n = n % 16;
		n = n / 16;
		if (n > 0)
			ft_putnbrhex_fd(n, fd);
		display_n_char = base[display_n];
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