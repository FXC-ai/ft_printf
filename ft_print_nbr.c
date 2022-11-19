/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:13:05 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/19 11:13:42 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_nbr(va_list args, int *c_count)
{
	int nbr_to_print;

	nbr_to_print = va_arg(args, int);
	ft_putnbr_fd(nbr_to_print, 1);
	*c_count += ft_strlen(ft_itoa(nbr_to_print));
}