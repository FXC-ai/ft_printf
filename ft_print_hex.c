/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:52:30 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/20 12:59:09 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "ft_printf.h"

static int	ft_hex_len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

static void	ft_print_hexa_process(unsigned int nb, char *base)
{
	if (nb > 0)
	{
		ft_print_hexa_process(nb / 16, base);
		ft_putchar_fd(base[nb % 16], 1);
	}
}

void	ft_print_hex(va_list args, int *ptr_c_count)
{
	char *base = "0123456789abcdef";
	unsigned int nb;

	nb = va_arg(args, unsigned int);
	if (nb == 0)
	{
		ft_putchar_fd('0', 1);
		*ptr_c_count += 1;
	}
	else
	{
		ft_print_hexa_process(nb, base);
		*ptr_c_count += ft_hex_len(nb);
	}
}*/



#include "ft_printf.h"

void	ft_print_hex(va_list args, char *base, int *ptr_c_count)
{
	unsigned int hex_to_print;

	hex_to_print = va_arg(args, unsigned int);
	
	ft_putnbr_hex_fd(hex_to_print, base, 1);

	if (hex_to_print == 0)
	{
		ft_putchar_fd('0', 1);
		*ptr_c_count += 1;
	}
	
	while (hex_to_print > 0)
	{
		hex_to_print = hex_to_print / 16;
		*ptr_c_count += 1;
	}
}
