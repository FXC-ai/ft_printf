/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:13:05 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/19 17:13:36 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_print_nbr(va_list args, int *c_count)
{
	int nbr_to_print;
	char *nbr_to_print_char;

	nbr_to_print = va_arg(args, int);
	//printf("\n\n le PB = %d \n\n", nbr_to_print);

	ft_putnbr_fd(nbr_to_print, 1);

	nbr_to_print_char = ft_itoa(nbr_to_print);

	*c_count += ft_strlen(nbr_to_print_char);

	free(nbr_to_print_char);
}