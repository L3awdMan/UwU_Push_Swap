/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zotaj-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:28:10 by zotaj-di          #+#    #+#             */
/*   Updated: 2025/05/15 20:49:09 by zotaj-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
void	test(const char *s, int c)
{
	char	*result_std;
	char	*result_ft;

	result_std = strchr(s, c);
	result_ft = ft_strchr(s, c);
	printf("Input string: \"%s\", char: '%c' (%d)\n", s, c, c);
	printf("  strchr   -> %s\n", result_std ? result_std : "NULL");
	printf("  ft_strchr-> %s\n", result_ft ? result_ft : "NULL");
	printf("%s\n\n", (result_std == result_ft) ? "✅ PASS" : "❌ FAIL");
}

int	main(void)
{
	const char	weird[] = {'a', 'b', '\0', 'c', '\0'};

	// Normal case
	test("hello world", 'o');
	// Not found
	test("hello", 'x');
	// Null terminator
	test("42 Network", '\0');
	// Char after \0 (should never be found)
	test(weird, 'c');
	// High ASCII char
	test("abc\xA9xyz", 0xA9); // © symbol in extended ASCII
	return (0);
}


//int	main(void)
//{
	//char	*pew = "ongol f*ck";
//	char	s = 'l';

//	printf("l f*ck : %s\n", ft_strchr(pew, s));
//}*/
