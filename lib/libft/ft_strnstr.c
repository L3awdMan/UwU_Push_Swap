/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 23:03:22 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/05/15 21:20:23 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int		i;
	size_t	len_to_find;

	len_to_find = ft_strlen(to_find);
	if (len_to_find == 0)
		return ((char *)str);
	if (len == 0)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == to_find[0])
			if (ft_strncmp((str + i), to_find, len_to_find) == 0)
				if ((i + len_to_find) <= len)
					return ((char *)str + i);
		i++;
	}
	return (NULL);
}
/*
void	test(const char *haystack, const char *needle, size_t len)
{
	char	*result;

	result = ft_strnstr(haystack, needle, len);
	if (needle[0] == '\0')
		printf("Searching for empty string in \"%s\" with len=%zu → %s\n",
			haystack, len, result == haystack ? "✅ OK" : "❌ FAIL");
	else if (result)
		printf("Found \"%s\" in \"%s\" with len=%zu at: \"%s\" ✅\n", needle,
			haystack, len, result);
	else
		printf("Did NOT find \"%s\" in \"%s\" with len=%zu ❌\n", needle,
			haystack, len);
}

int	main(void)
{
	test("oh no not the empty string !", "", 0); // ✅ should return the haystack
	test("hello world", "world", 11);            // ✅ should find "world"
	test("hello world", "world", 5);
		// ❌ should not find it (too short)
	test("aaaaa", "bba", 5);                     // ❌ should return NULL
	test("test123test", "123", 7);               // ✅ should find at index 4
	test("test123test", "1234", 8);              // ❌ should return NULL
}*/
