/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:52:21 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/06/25 23:39:28 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int nb)
{
	int		length;
	long	nbr;

	length = 0;
	nbr = nb;
	if (nbr < 0)
	{
		length += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
		length += ft_print_nbr(nbr / 10);
	length += ft_print_char((nbr % 10) + '0');
	return (length);
}
/*
int	main(void)
{
	int	len;

	len = ft_print_nbr(42); // prints 42
	write(1, "\n", 1);
	len = ft_print_nbr(-12345); // prints -12345
	write(1, "\n", 1);
	len = ft_print_nbr(-2147483648); // prints -2147483648
	write(1, "\n", 1);
	return (0);
}*/
