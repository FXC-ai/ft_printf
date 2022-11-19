/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:25:37 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/19 17:53:35 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(va_list args, int *ptr_c_count)
{
	unsigned long ptr_to_print;

	ptr_to_print = va_arg(args, unsigned long);
	ft_putstr_fd("0x",1);
	*ptr_c_count += 2;
	ft_putnbrhex_fd(ptr_to_print, 1);
	if (ptr_to_print == 0)
		*ptr_c_count += 1;
	while (ptr_to_print >= 1)
	{
		ptr_to_print = ptr_to_print / 16;
		*ptr_c_count += 1;
	}
}
