/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:28:48 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/05/15 17:19:28 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	length;
	char	*str;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	str = (char *)malloc(length + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < length)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <ctype.h>

char	ft_toupper_even(unsigned int i, char c)
{
	if (i % 2 == 0 && isalpha(c))
		return (toupper(c));
	return (c);
}

void	test_strmapi(const char *input, char (*f)(unsigned int, char),
		const char *expected)
{
	char	*result;

	result = ft_strmapi(input, f);
	if (!input)
	{
		if (result == NULL)
			printf("✅ Passed NULL input test.\n");
		else
			printf("❌ Failed NULL input test.\n");
		return ;
	}
	if (!result)
	{
		printf("❌ Malloc failed or NULL returned unexpectedly.\n");
		return ;
	}
	if (strcmp(result, expected) == 0)
		printf("✅ Passed: \"%s\" → \"%s\"\n", input, result);
	else
		printf("❌ Failed: \"%s\" → \"%s\" (Expected: \"%s\")\n", input, result,
			expected);
	free(result);
}

int	main(void)
{
	test_strmapi("hello", ft_toupper_even, "HeLlO");
	test_strmapi("42Network", ft_toupper_even, "42NeTwOrK");
	test_strmapi("", ft_toupper_even, "");     // Empty string test
	test_strmapi(NULL, ft_toupper_even, NULL); // NULL string test
	return (0);
}*/
