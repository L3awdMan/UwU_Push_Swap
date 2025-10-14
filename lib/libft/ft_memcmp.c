/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:49:19 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/05/06 19:01:15 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char a[] = "abcde";
	char b[] = "abcdf";
	char c[] = "abcde";
	char d[] = "abcd\xff"; // to test unsigned comparison

	// Test 1: Equal strings
	printf("Test 1: %d (expected 0)\n", ft_memcmp(a, c, 5));

	// Test 2: Different last character
	printf("Test 2: %d (expected negative)\n", ft_memcmp(a, b, 5));

	// Test 3: n less than length, same first bytes
	printf("Test 3: %d (expected 0)\n", ft_memcmp(a, b, 4));

	// Test 4: Unsigned byte comparison
	printf("Test 4: %d (expected negative)\n", ft_memcmp(a, d, 5));

	// Test 5: Zero length comparison
	printf("Test 5: %d (expected 0)\n", ft_memcmp(a, b, 0));

	return (0);
}*/
