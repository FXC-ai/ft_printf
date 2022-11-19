/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:52:30 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/19 21:52:04 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(va_list args, int *ptr_c_count)
{
	long long hex_to_print;

	hex_to_print = va_arg(args, long long);
	
	ft_putnbr_hex_fd(hex_to_print, 1);

	if (hex_to_print == 0)
		*ptr_c_count += 1;
	while (hex_to_print >= 1)
	{
		hex_to_print = hex_to_print / 16;
		*ptr_c_count += 1;
	}
}
