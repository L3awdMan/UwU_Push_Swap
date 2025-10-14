/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:15:52 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/05/13 23:47:07 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*   cut unwanted characters "set" in the bigining and the end   */

#include "libft.h"

static int	ft_check_set(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	len_s1;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	while (s1)
	{
		if (ft_check_set(((char)*s1), set) == 1)
			s1++;
		else
			break ;
	}
	len_s1 = ft_strlen(s1);
	while (len_s1 != 0)
	{
		if (ft_check_set(s1[len_s1 - 1], set) == 1)
			len_s1--;
		else
			break ;
	}
	str = (char *)malloc(len_s1 + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)s1, (len_s1 + 1));
	return (str);
}
/*
void	test_strtrim(const char *s1, const char *set, const char *expected)
{
	char	*result;

	result = ft_strtrim(s1, set);
	if (!result)
		printf("ft_strtrim(\"%s\", \"%s\") = NULL\n", s1, set);
	else if (strcmp(result, expected) == 0)
		printf("✅ PASSED: ft_strtrim(\"%s\", \"%s\") = \"%s\"\n", s1, set,
			result);
	else
		printf("FAILED: ft_strtrim(\"%s\",\"%s\") = \"%s\" (Expected: \"%s\")\n",
			s1, set, result, expected);
	free(result);
}

int	main(void)
{
	printf("=== ft_strtrim Test Cases ===\n\n");
	// Basic trimming
	test_strtrim("   hello world   ", " ", "hello world");
	test_strtrim("$$$Hello$$$", "$", "Hello");
	test_strtrim("xx42xx", "x", "42");
	test_strtrim("***C student***", "*", "C student");
	// Full trim (all characters)
	test_strtrim("aaaaaa", "a", ""); // Should return empty string
	// Nothing to trim
	test_strtrim("42", "abc", "42");
	// Characters only at one side
	test_strtrim("abc42", "abc", "42");
	test_strtrim("42abc", "abc", "42");
	// Mixed trim
	test_strtrim("abcabc42abc", "abc", "42");
	// Empty string input
	test_strtrim("", " ", "");
	test_strtrim("", "", "");
	// Empty set
	test_strtrim("hello", "", "hello");
	// NULL inputs
	test_strtrim(NULL, "abc", NULL);
	test_strtrim("hello", NULL, NULL);
	return (0);
}*/
