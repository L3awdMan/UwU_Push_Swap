/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:36:49 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/07/01 17:51:52 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(uintptr_t ptr)
{
	int	length;

	length = 0;
	while (ptr != 0)
	{
		length++;
		ptr /= 16;
	}
	return (length);
}

void	ft_put_ptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_put_ptr((ptr / 16));
		ft_put_ptr((ptr % 16));
	}
	else
	{
		if (ptr <= 9)
			ft_print_char((ptr + '0'));
		else
			ft_print_char(ptr - 10 + 'a');
	}
}

int	ft_print_ptr(uintptr_t ptr)
{
	int	length;

	length = 0;
	if (ptr == 0)
		length += write(1, "(nil)", 5);
	else
	{
		length += write(1, "0x", 2);
		ft_put_ptr(ptr);
		length += ft_ptr_len(ptr);
	}
	return (length);
}
/*
int	main(void)
{
	void	*ptr1;
	int		*ptr2;
	char	dummy;
	void	*ptr3;

	// 🔹 Test Case 1: Simple (NULL pointer)
	ptr1 = NULL;
	printf("Test 1 (NULL): ");
	// write() and ft_print_char are low level output so it print before printf
	// printf uses buffered output so the terminal sees the ft_print_char first
	fflush(stdout);
	ft_print_ptr((uintptr_t)ptr1);
	printf("\n");
	// 🔹 Test Case 2: Mid-range (allocated int)
	ptr2 = malloc(sizeof(int));
	*ptr2 = 42;
	printf("Test 2 (malloc'd int): ");
	fflush(stdout);
	ft_print_ptr((uintptr_t)ptr2);
	printf(" (actual: %p)\n", (void *)ptr2);
	free(ptr2);
	// 🔹 Test Case 3: Hard (high address stack pointer)
	ptr3 = &dummy;
	printf("Test 3 (stack addr): ");
	fflush(stdout);
	ft_print_ptr((uintptr_t)ptr3);
	printf(" (actual: %p)\n", (void *)ptr3);
	// Test Case 4 : NULL pointer
	printf("Test 4 (NULL pointer): ");
	ft_print_ptr((unsigned long long)NULL);
	printf(" (expected: (nil))\n");
	return (0);
}*/
