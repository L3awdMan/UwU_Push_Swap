/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:26:47 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/07/03 18:52:08 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifier(va_list arg, const char the_specifier)
{
	int	printf_len;

	printf_len = 0;
	if (the_specifier == 'c')
		printf_len += ft_print_char(va_arg(arg, int));
	else if (the_specifier == '%')
		printf_len += ft_print_char('%');
	else if (the_specifier == 's')
		printf_len += ft_print_str(va_arg(arg, char *));
	else if (the_specifier == 'd' || the_specifier == 'i')
		printf_len += ft_print_nbr(va_arg(arg, int));
	else if (the_specifier == 'x' || the_specifier == 'X')
		printf_len += ft_print_hex(va_arg(arg, unsigned int), the_specifier);
	else if (the_specifier == 'p')
		printf_len += ft_print_ptr(va_arg(arg, uintptr_t));
	else if (the_specifier == 'u')
		printf_len += ft_print_unsigned(va_arg(arg, unsigned int));
	return (printf_len);
}

int	ft_printf(const char *str, ...)
{
	int		printf_len;
	int		i;
	va_list	arg;

	if (!str)
		return (-1);
	i = 0;
	printf_len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			printf_len += ft_specifier(arg, str[i + 1]);
			i++;
		}
		else
			printf_len += ft_print_char(str[i]);
		i++;
	}
	return (printf_len);
}
