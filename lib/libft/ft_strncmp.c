/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:09:21 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/05/06 20:02:25 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 				strcmp = compare the entier string
					strncmp = compare up to 'n' characters
			WARNING ! :  what matter the most is the SIGN not the VALUE    */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while ((str1[i] == str2[i]) && (i < n))
	{
		if (str1[i] == '\0')
			return (0);
		i++;
	}
	if (i == n)
		return (0);
	return (str1[i] - str2[i]);
}
/*
int	main(void)
{
	printf("Test 1: %d vs %d\n", ft_strncmp("abc", "abc", 3), strncmp("abc",
			"abc", 3));
	printf("Test 2: %d vs %d\n", ft_strncmp("abc", "abd", 3), strncmp("abc",
			"abd", 3));
	printf("Test 3: %d vs %d\n", ft_strncmp("abc", "abc", 0), strncmp("abc",
			"abc", 0));
	printf("Test 4: %d vs %d\n", ft_strncmp("abc", "ab", 3), strncmp("abc",
			"ab", 3));
	printf("Test 5: %d vs %d\n", ft_strncmp("ab", "abc", 3), strncmp("ab",
			"abc", 3));
	printf("Test 6: %d vs %d\n", ft_strncmp("", "", 1), strncmp("", "", 1));
	printf("Test 7: %d vs %d\n", ft_strncmp("a", "", 1), strncmp("a", "", 1));
	printf("Test 8: %d vs %d\n", ft_strncmp("abc", "abcde", 4), strncmp("abc",
			"abcde", 4));
	return (0);
}*/
