/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uint_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:10:29 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/19 19:20:39 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_uint_fd(unsigned int n, int fd)
{
	unsigned int	display_n;
	int	display_n_char;

	display_n_char = 0;

	if (n == 0)
		write(fd, "0", 1);
	if (n >= 1)
	{
		display_n = n % 10;
		n = n / 10;
		if (n > 0)
			ft_putnbr_uint_fd(n, fd);
		display_n_char = display_n + 48;
		write(fd, &display_n_char, 1);
	}
}
