/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:06:56 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/19 19:44:36 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_uint(va_list args, int *ptr_c_count)
{
	unsigned int nbr_to_print;

	nbr_to_print = va_arg(args, unsigned int);

	ft_putnbr_uint_fd(nbr_to_print, 1);

	if (nbr_to_print == 0)
	{
		*ptr_c_count += 1;
	}
	

	while (nbr_to_print > 0)
	{
		nbr_to_print = nbr_to_print / 10;
		*ptr_c_count += 1;
	}
	
}