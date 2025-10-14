/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:25:10 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/07/01 17:51:18 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int num)
{
	int	lenght;

	lenght = 0;
	while (num != 0)
	{
		lenght++;
		num /= 16;
	}
	return (lenght);
}

void	ft_put_hex(unsigned int num, const char specifier)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, specifier);
		ft_put_hex(num % 16, specifier);
	}
	else
	{
		if (num <= 9)
			ft_print_char((num + '0'));
		else
		{
			if (specifier == 'x')
				ft_print_char((num - 10 + 'a'));
			if (specifier == 'X')
				ft_print_char((num - 10 + 'A'));
		}
	}
}

int	ft_print_hex(unsigned int num, const char specifier)
{
	if (num == 0)
		return (ft_print_char('0'));
	else
		ft_put_hex(num, specifier);
	return (ft_hex_len(num));
}
/*
int	main(void)
{
	ft_print_hex(255, 'x');
	write(1, "\n", 1);
	ft_put_hex(3735928559, 'X');
	write(1, "\n", 1);
	ft_put_hex(0, 'X');
	printf("\n");
}*/
