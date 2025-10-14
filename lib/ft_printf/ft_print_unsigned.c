/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:56:44 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/07/01 17:53:03 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(unsigned int num)
{
	int	length;

	length = 0;
	while (num != 0)
	{
		length++;
		num /= 10;
	}
	return (length);
}

char	*ft_unsigned_itoa(unsigned int number)
{
	char	*num;
	int		length;

	length = ft_num_len(number);
	num = (char *)malloc(length + 1);
	if (!num)
		return (0);
	num[length] = '\0';
	while (number != 0)
	{
		num[length - 1] = number % 10 + '0';
		number /= 10;
		length--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int number)
{
	int		length;
	char	*num;

	length = 0;
	if (number == 0)
		length += write(1, "0", 1);
	else
	{
		num = ft_unsigned_itoa(number);
		length += ft_print_str(num);
		free(num);
	}
	return (length);
}

/*
#include <limits.h>

int	main(void)
{
	// 🧪 Test 1: Simple small number
	printf("Test 1 (simple unsigned): ");
	fflush(stdout);
	ft_print_unsigned(42);
	printf(" (expected: 42)\n");
	// 🧪 Test 2: Maximum unsigned int
	printf("Test 2 (UINT_MAX): ");
	fflush(stdout);
	ft_print_unsigned(UINT_MAX);
	printf(" (expected: %u)\n", UINT_MAX);
	return (0);
}*/
