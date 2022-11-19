/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:26:45 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/19 11:28:38 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbrhex_fd(unsigned long n, int fd)
{
	unsigned long		display_n;
	char				display_n_char;
	char 				*base;

	base = "0123456789abcdef";
	display_n_char = 0;
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
