/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:25:37 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/19 11:26:00 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_hex(va_list args, int *c_count)
{
	unsigned long ptr_to_print;

	ptr_to_print = va_arg(args, unsigned long);
	ft_putstr_fd("0x",1);
	*c_count += 2;
	ft_putnbrhex_fd(ptr_to_print, 1);
	while (ptr_to_print >= 1)
	{
		ptr_to_print = ptr_to_print / 16;
		*c_count += 1;
	}
}
